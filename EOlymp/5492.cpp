#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    set<char> letters;
    for (int i = 0; i < n; i++)
        letters.insert(i + 'a');

    for (int r = s.size() / 2, l = s.size() - 1 - r; l >= 0; l--, r++) {
        if (s[l] != '?' || s[r] != '?') {
            if (s[l] == '?')
                s[l] = s[r];
            if (s[r] == '?')
                s[r] = s[l];
            if (s[l] != s[r]) {
                cout << "IMPOSSIBLE";
                return;
            }
            letters.erase(s[l]);
        }
    }

    for (int r = s.size() / 2, l = s.size() - 1 - r; l >= 0; l--, r++) {
        if (s[l] == '?') {
            if (letters.empty()) {
                s[l] = s[r] = 'a';
            } else {
                s[l] = s[r] = *prev(letters.end());
                letters.erase(prev(letters.end()));
            }
        }
    }

    cout << (letters.empty() ? s : "IMPOSSIBLE");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 1;
    //cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}