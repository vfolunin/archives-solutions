#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int side, pointCount;
    cin >> side >> pointCount;

    vector<pair<int, int>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    sort(points.begin(), points.end());

    for (int cx = 0; cx <= side; cx++) {
        for (int cy = 0; cy <= side; cy++) {
            if (binary_search(points.begin(), points.end(), pair(cx, cy)))
                continue;

            int dist2 = min(min(cx, side - cx), min(cy, side - cy));
            dist2 *= dist2;

            bool ok = 1;
            for (auto &[x, y] : points) {
                if ((x - cx) * (x - cx) + (y - cy) * (y - cy) > dist2) {
                    ok = 0;
                    break;
                }
            }

            if (ok) {
                cout << cx << " " << cy << "\n";
                return;
            }
        }
    }

    cout << "poodle\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}