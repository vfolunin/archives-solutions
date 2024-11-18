#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string getLarger(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() > b.size() ? a : b;
    return a > b ? a : b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<vector<string>> res(2, vector<string>(1 << 10));

    for (int i = s.size() - 1; i >= 0; i--) {
        int digit = s[i] - '0';
        fill(res[0].begin(), res[0].end(), 0);

        for (int mask = 0; mask < (1 << 10); mask++) {
            res[0][mask] = res[1][mask];
            if (mask & (1 << digit))
                res[0][mask] = getLarger(res[0][mask], s[i] + res[1][mask ^ (1 << digit)]);
        }

        res[1].swap(res[0]);
    }

    string ans;
    for (int mask = 0; mask < (1 << 10); mask++)
        ans = getLarger(ans, res[1][mask]);

    cout << ans;
}