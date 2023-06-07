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
    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            for (int m = l; m < r; m++)
                if (res[l][r].size() < res[l][m].size() + res[m + 1][r].size())
                    res[l][r] = res[l][m] + res[m + 1][r];

            if ((s[l] == '(' && s[r] == ')' || s[l] == '[' && s[r] == ']' || s[l] == '{' && s[r] == '}') &&
                res[l][r].size() < res[l + 1][r - 1].size() + 2)
                res[l][r] = s[l] + res[l + 1][r - 1] + s[r];
        }
    }

    cout << res[0][s.size() - 1];
}