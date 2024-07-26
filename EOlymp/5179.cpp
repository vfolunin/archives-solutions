#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getPeriod(const string &s) {
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && s[i] != s[border])
            border = p[border - 1];
        p[i] = border + (s[i] == s[border]);
    }
    int period = s.size() - p.back();
    return s.size() % period ? s.size() : period;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    string s;
    cin >> s;

    vector<vector<string>> res(s.size(), vector<string>(s.size()));

    for (int i = 0; i < s.size(); i++)
        res[i][i] = string(1, s[i]);

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            res[l][r] = s.substr(l, r - l + 1);

            for (int m = l; m < r; m++) {
                string candidate = res[l][m] + res[m + 1][r];
                if (res[l][r].size() > candidate.size())
                    res[l][r] = candidate;
            }

            int period = getPeriod(s.substr(l, r - l + 1));
            string candidate = to_string((r - l + 1) / period) + "(" + res[l][l + period - 1] + ")";
            if (res[l][r].size() > candidate.size())
                res[l][r] = candidate;
        }
    }

    cout << res[0][s.size() - 1];
}