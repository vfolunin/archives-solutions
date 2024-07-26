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

    vector<vector<long long>> res(s.size(), vector<long long>(s.size()));

    for (int i = 0; i < s.size(); i++)
        res[i][i] = 1;

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (s[l] == s[r])
                res[l][r] = res[l + 1][r] + res[l][r - 1] + 1;
            else
                res[l][r] = res[l + 1][r] + res[l][r - 1] - res[l + 1][r - 1];
        }
    }

    cout << res[0][s.size() - 1];
}