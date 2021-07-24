#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    int k;
    cin >> s >> k;

    int res = 0;

    for (int i = 0; i < s.size(); i++) {
        for (int l = i, r = i, curK = k; 1; l--, r++) {
            if (l < 0 || r >= s.size() || s[l] != s[r] && !curK) {
                res = max(res, r - l - 1);
                break;
            }
            if (s[l] != s[r])
                curK--;
        }
    }

    for (int i = 0; i + 1 < s.size(); i++) {
        for (int l = i, r = i + 1, curK = k; 1; l--, r++) {
            if (l < 0 || r >= s.size() || s[l] != s[r] && !curK) {
                res = max(res, r - l - 1);
                break;
            }
            if (s[l] != s[r])
                curK--;
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}