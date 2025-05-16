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

    while (!s.empty() && s.back() == '0')
        s.pop_back();

    for (int l = 0, r = (int)s.size() - 1; l < r; l++, r--) {
        if (s[l] != s[r]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}