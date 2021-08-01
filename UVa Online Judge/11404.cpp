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

    vector<vector<string>> pal(s.size(), vector<string>(s.size()));

    for (int i = 0; i < s.size(); i++)
        pal[i][i] = string(1, s[i]);

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (s[l] == s[r])
                pal[l][r] = s[l] + pal[l + 1][r - 1] + s[r];
            else if (pal[l][r - 1].size() > pal[l + 1][r].size() ||
                     pal[l][r - 1].size() == pal[l + 1][r].size() && pal[l][r - 1] < pal[l + 1][r])
                pal[l][r] = pal[l][r - 1];
            else
                pal[l][r] = pal[l + 1][r];
        }
    }

    cout << pal[0][s.size() - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}