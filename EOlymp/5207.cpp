#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string rec(string &s, int l, int r, vector<vector<pair<int, int>>> &from) {
    if (l > r)
        return "";
    if (l == r)
        return string(1, s[l]);

    string res = rec(s, from[l][r].first, from[l][r].second, from);
    if (s[l] == s[r])
        res = s[l] + res + s[r];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<vector<int>> res(s.size(), vector<int>(s.size()));
    vector<vector<pair<int, int>>> from(s.size(), vector<pair<int, int>>(s.size()));

    for (int i = 0; i < s.size(); i++)
        res[i][i] = 1;

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (s[l] == s[r]) {
                res[l][r] = res[l + 1][r - 1] + 2;
                from[l][r] = { l + 1, r - 1 };
            } else if (res[l + 1][r] > res[l][r - 1]) {
                res[l][r] = res[l + 1][r];
                from[l][r] = { l + 1, r };
            } else {
                res[l][r] = res[l][r - 1];
                from[l][r] = { l, r - 1 };
            }
        }
    }

    cout << rec(s, 0, s.size() - 1, from);
}