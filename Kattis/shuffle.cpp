#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int windowWidth, width;
    cin >> windowWidth >> width;

    vector<int> songs(width);
    for (int &song : songs)
        cin >> song;

    vector<int> can(windowWidth, 1);
    map<int, int> window;

    for (int l = -windowWidth + 1, r = 0; l < width; l++, r++) {
        if (r < width)
            window[songs[r]]++;
        if (window.size() != min(r, width - 1) - max(l, 0) + 1)
            can[r % windowWidth] = 0;
        if (0 <= l && !--window[songs[l]])
            window.erase(songs[l]);
    }

    int res = 0;
    for (int c : can)
        res += c;

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