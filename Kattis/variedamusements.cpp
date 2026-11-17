#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    vector<int> count(3);
    cin >> size >> count[0] >> count[1] >> count[2];

    const long long MOD = 1e9 + 7;
    vector<vector<long long>> ways(size, vector<long long>(3));
    ways[0].assign(count.begin(), count.end());

    for (int i = 1; i < size; i++)
        for (int last = 0; last < 3; last++)
            for (int prev = 0; prev < 3; prev++)
                if (prev != last)
                    ways[i][last] = (ways[i][last] + ways[i - 1][prev] * count[last]) % MOD;
    
    cout << (ways.back()[0] + ways.back()[1] + ways.back()[2]) % MOD;
}