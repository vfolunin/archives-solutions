#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    int specialPosCount;
    cin >> specialPosCount;

    vector<bool> isSpecial(s.size());
    for (int i = 0; i < specialPosCount; i++) {
        int pos;
        cin >> pos;
        isSpecial[pos - 1] = 1;
    }

    vector<vector<pair<int, int>>> pal(s.size(), vector<pair<int, int>>(s.size()));
    pair<int, int> res = { 0, 0 };

    for (int i = 0; i < s.size(); i++) {
        pal[i][i] = { isSpecial[i], 1 };
        res = max(res, pal[i][i]);
    }

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (s[l] == s[r]) {
                auto [s, w] = pal[l + 1][r - 1];
                pal[l][r] = { s + isSpecial[l] + isSpecial[r], w + 2 };
            }
            pal[l][r] = max(pal[l][r], pal[l][r - 1]);
            pal[l][r] = max(pal[l][r], pal[l + 1][r]);
            res = max(res, pal[l][r]);
        }
    }

    cout << res.second << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}