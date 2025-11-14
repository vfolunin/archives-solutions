#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> compatible(size, vector<int>(size));
    for (int a = 0; a < size; a++)
        for (int b = 0; b < size; b++)
            cin >> compatible[a][b];

    vector<vector<long long>> ways(size, vector<long long>(1 << size));
    const long long MOD = 1e9 + 7;

    for (int b = 0; b < size; b++)
        ways[0][1 << b] = compatible[0][b];

    for (int a = 1; a < size; a++)
        for (int mask = 0; mask < (1 << size); mask++)
            if (ones(mask) == a + 1)
                for (int b = 0; b < size; b++)
                    if (compatible[a][b] && (mask & (1 << b)))
                        ways[a][mask] = (ways[a][mask] + ways[a - 1][mask ^ (1 << b)]) % MOD;

    cout << ways[size - 1][(1 << size) - 1];
}