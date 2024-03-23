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

    int x = 0, y = 0;
    for (char c : s) {
        x -= c == '<';
        x += c == '>';
        y -= c == 'v';
        y += c == '^';
    }

    cout << x << " " << y << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}