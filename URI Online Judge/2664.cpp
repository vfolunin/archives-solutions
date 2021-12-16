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

    int time, l, r;
    cin >> time >> l >> r;

    vector<vector<long long>> ways(time, vector<long long>(r + 1));

    for (int i = l; i <= r; i++)
        ways[0][i] = 1;

    for (int t = 1; t < time; t++) {
        ways[t][l] = ways[t - 1][l + 1];
        for (int i = l + 1; i < r; i++)
            ways[t][i] = (ways[t - 1][i - 1] + ways[t - 1][i + 1]) % MOD;
        ways[t][r] = ways[t - 1][r - 1];
    }

    long long res = 0;
    for (int i = l; i <= r; i++)
        res = (res + ways[time - 1][i]) % MOD;

    cout << res << "\n";
}