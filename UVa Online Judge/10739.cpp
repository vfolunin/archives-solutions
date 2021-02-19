#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    cin >> s;

    vector<vector<int>> moves(s.size(), vector<int>(s.size()));

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (s[l] == s[r])
                moves[l][r] = moves[l + 1][r - 1];
            else
                moves[l][r] = 1 + min(min(moves[l + 1][r], moves[l][r - 1]), moves[l + 1][r - 1]);
        }
    }

    cout << "Case " << test << ": " << moves[0][s.size() - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}