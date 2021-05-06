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

    int m = s.find('M');
    if (m == -1) {
        cout << "no-theorem\n";
        return;
    }

    int e = s.find('E');
    if (e < m) {
        cout << "no-theorem\n";
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '?' && i != m && i != e) {
            cout << "no-theorem\n";
            return;
        }
    }

    int a = m, b = e - 1 - m, c = s.size() - 1 - e;

    cout << (a && b && a + b == c ? "theorem\n" : "no-theorem\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}