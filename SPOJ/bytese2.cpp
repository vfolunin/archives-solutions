#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int segmentCount;
    cin >> segmentCount;

    map<int, int> delta;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        delta[l]++;
        delta[r]--;
    }

    int cur = 0, res = 0;
    for (auto &[_, delta] : delta) {
        cur += delta;
        res = max(res, cur);
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