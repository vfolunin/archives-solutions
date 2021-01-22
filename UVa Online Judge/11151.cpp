#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    getline(cin, s);

    if (s.empty()) {
        cout << "0\n";
        return;
    }

    vector<vector<int>> palindromeLen(s.size(), vector<int>(s.size()));
    for (int i = 0; i < s.size(); i++)
        palindromeLen[i][i] = 1;
    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = l + len - 1; r < s.size(); l++, r++) {
            if (s[l] == s[r])
                palindromeLen[l][r] = 2 + palindromeLen[l + 1][r - 1];
            else
                palindromeLen[l][r] = max(palindromeLen[l + 1][r], palindromeLen[l][r - 1]);
        }
    }

    cout << palindromeLen[0][s.size() - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}