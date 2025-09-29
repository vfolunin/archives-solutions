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

    int level = (s[0] - '1') * 4 + s[2] - '1';

    int res = 0;
    if (level < 2) {
        res += 2 - level;
        level = 12;
    }
    if (level < 14) {
        res += 14 - level;
        level = 28;
    }
    res += 32 - level;

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