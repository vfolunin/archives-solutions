#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<pair<int, int>> cuts(h + w - 2);
    for (int i = 0; i < h - 1; i++) {
        cin >> cuts[i].first;
    }
    for (int i = 0; i < w - 1; i++) {
        cin >> cuts[h - 1 + i].first;
        cuts[h - 1 + i].second = 1;
    }

    sort(cuts.rbegin(), cuts.rend());
    long long res = 0, pieces[] = { 1, 1 };

    for (auto [cost, type] : cuts) {
        res += cost * pieces[1 - type];
        pieces[type]++;
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