#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    const long long MOD = 1e9 + 7;
    vector<vector<long long>> ways(1e6 + 1, vector<long long>(2));
    ways[1] = { 1, 1 };

    for (int i = 2; i < ways.size(); i++) {
        ways[i][0] = (ways[i - 1][0] * 2 + ways[i - 1][1]) % MOD;
        ways[i][1] = (ways[i - 1][0] + ways[i - 1][1] * 4) % MOD;
    }

    vector<long long> res(ways.size());
    for (int i = 0; i < res.size(); i++)
        res[i] = (ways[i][0] + ways[i][1]) % MOD;
    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<long long> res = prepare();

    cout << res[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}