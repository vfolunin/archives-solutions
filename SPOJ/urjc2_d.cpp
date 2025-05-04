#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string symbols, s;
    cin >> symbols >> s;

    unordered_set<char> seen(symbols.begin(), symbols.end());
    int res = 0;

    for (char c : s) {
        res += seen.count(c) ? 50 : 150;
        seen.insert(c);
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