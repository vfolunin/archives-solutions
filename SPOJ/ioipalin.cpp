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
    cin >> s >> s;

    vector<vector<int>> res(s.size(), vector<int>(s.size()));
    for (int i = 0; i < s.size(); i++)
        res[i][i] = 1;

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (s[l] == s[r])
                res[l][r] = res[l + 1][r - 1] + 2;
            else
                res[l][r] = max(res[l + 1][r], res[l][r - 1]);
        }
    }

    cout << s.size() - res[0][s.size() - 1];
}