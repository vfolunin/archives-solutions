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

    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == s[i + 1]) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}