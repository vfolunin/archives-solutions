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

    string s;
    cin >> s;

    if (s.empty()) {
        cout << "";
        return 0;
    }

    vector<vector<string>> res(s.size(), vector<string>(s.size()));
    for (int i = 0; i < s.size(); i++)
        res[i][i] = s[i] == '(' || s[i] == ')' ? "()" : "[]";

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (s[l] == '(' && s[r] == ')')
                res[l][r] = "(" + res[l + 1][r - 1] + ")";
            else if (s[l] == '[' && s[r] == ']')
                res[l][r] = "[" + res[l + 1][r - 1] + "]";

            for (int m = l; m < r; m++) {
                string candidate = res[l][m] + res[m + 1][r];
                if (res[l][r].empty() || res[l][r].size() > candidate.size())
                    res[l][r] = candidate;
            }
        }
    }

    cout << res[0][s.size() - 1];
}