#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9;

long long rec(string &s, int l, int r, vector<vector<long long>> &memo) {
    long long &res = memo[l][r];
    if (res != -1)
        return res;

    if (l > r || s[l] != s[r])
        return res = 0;

    if (l == r)
        return res = 1;

    res = 0;
    for (int m = l + 1; m <= r; m++)
        if (s[l] == s[m])
            res = (res + rec(s, l + 1, m - 1, memo) * rec(s, m, r, memo)) % MOD;
    return res;
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    vector<vector<long long>> memo(s.size(), vector<long long>(s.size(), -1));
    long long res = rec(s, 0, s.size() - 1, memo);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}