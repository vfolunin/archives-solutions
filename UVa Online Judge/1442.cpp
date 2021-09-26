#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int width;
    cin >> width;

    vector<int> bottom(width);
    for (int &h : bottom)
        cin >> h;

    vector<int> top(width);
    for (int &h : top)
        cin >> h;

    vector<int> level(width);

    for (int i = 0, l = 1e9; i < width; i++) {
        l = max(l, bottom[i]);
        l = min(l, top[i]);
        level[i] = l;
    }

    for (int i = width - 1, l = 1e9; i >= 0; i--) {
        l = max(l, bottom[i]);
        l = min(l, top[i]);
        level[i] = min(level[i], l);
    }

    int res = 0;
    for (int i = 0; i < width; i++)
        res += level[i] - bottom[i];

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