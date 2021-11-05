#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<vector<int>> diag(h + w - 1);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int val;
            cin >> val;
            diag[y - x + w - 1].push_back(val);
        }
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;

        int res = 0;
        for (vector<int> &d : diag) {
            auto p = lower_bound(d.begin(), d.end(), l);
            auto q = upper_bound(d.begin(), d.end(), r);
            res = max<int>(res, q - p);
        }

        cout << res << "\n";
    }

    cout << "-\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}