#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<vector<int>> pal(s.size(), vector<int>(s.size()));

    for (int i = 0; i < s.size(); i++)
        pal[i][i] = 1;

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (s[l] == s[r])
                pal[l][r] = pal[l + 1][r - 1] + 2;
            else
                pal[l][r] = max(pal[l + 1][r], pal[l][r - 1]);
        }
    }

    cout << s.size() - pal[0][s.size() - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}