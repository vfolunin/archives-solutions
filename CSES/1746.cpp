#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, limit;
    cin >> n >> limit;

    vector<int> a(n);
    for (int &value : a)
        cin >> value;

    vector<vector<long long>> ways(2, vector<long long>(102));
    if (a[0])
        ways[0][a[0]] = 1;
    else
        fill(ways[0].begin() + 1, ways[0].begin() + limit + 1, 1);

    for (int i = 1; i < n; i++) {
        fill(ways[1].begin(), ways[1].end(), 0);
        if (a[i]) {
            ways[1][a[i]] = (ways[0][a[i] - 1] + ways[0][a[i]] + ways[0][a[i] + 1]) % MOD;
        } else {
            for (int value = 1; value <= limit; value++)
                ways[1][value] = (ways[0][value - 1] + ways[0][value] + ways[0][value + 1]) % MOD;
        }
        ways[0] = ways[1];
    }

    long long res = 0;
    for (int value = 1; value <= limit; value++)
        res = (res + ways[0][value]) % MOD;

    cout << res;
}