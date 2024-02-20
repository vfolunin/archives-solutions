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

    vector<vector<string>> res(s.size(), vector<string>(s.size()));

    for (int i = 0; i < s.size(); i++)
        res[i][i] = string(1, s[i]);

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (s[l] == s[r])
                res[l][r] = s[l] + res[l + 1][r - 1] + s[r];
            else if (res[l + 1][r].size() > res[l][r - 1].size())
                res[l][r] = res[l + 1][r];
            else
                res[l][r] = res[l][r - 1];
        }
    }

    cout << res[0][s.size() - 1].size() << "\n" << res[0][s.size() - 1];
}