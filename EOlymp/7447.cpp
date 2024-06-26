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

    vector<vector<int>> res(s.size(), vector<int>(s.size()));

    for (int i = 0; i < s.size(); i++)
        res[i][i] = 1;

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            res[l][r] = 1e9;
            for (int m = l; m < r; m++)
                res[l][r] = min(res[l][r], res[l][m] + res[m + 1][r]);
            if (s[l] == s[r])
                res[l][r] = min(res[l][r], res[l + 1][r - 1]);
        }
    }

    cout << res[0][s.size() - 1];
}