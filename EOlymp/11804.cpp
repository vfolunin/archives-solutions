#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int x, y;
    string s;
    cin >> s >> x >> y >> s;

    map<pair<int, int>, int> count;
    int maxCount = ++count[{ x, y }];

    for (char c : s) {
        x -= c == 'L';
        x += c == 'R';
        y -= c == 'D';
        y += c == 'U';
        maxCount = max(maxCount, ++count[{ x, y }]);
    }

    int res = 0;
    for (auto &[p, count] : count)
        res += count == maxCount;

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