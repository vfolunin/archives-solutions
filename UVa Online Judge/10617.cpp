#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<vector<long long>> palCount(s.size(), vector<long long>(s.size(), 1));

    for (int i = 0; i < s.size(); i++)
        palCount[i][i] = 2;

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            palCount[l][r] = palCount[l][r - 1] + 1;
            for (int i = l; i < r; i++)
                if (s[i] == s[r])
                    palCount[l][r] += palCount[i + 1][r - 1];
        }
    }

    cout << palCount[0][s.size() - 1] - 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}