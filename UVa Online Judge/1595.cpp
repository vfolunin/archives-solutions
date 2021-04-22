#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int pointCount;
    cin >> pointCount;

    map<pair<int, int>, int> points;

    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;
        x *= 2;
        points[{x, y}]++;
    }

    int mid = (points.begin()->first.first + points.rbegin()->first.first) / 2;

    for (auto &[p, count] : points) {
        if (p.first == mid)
            continue;

        pair<int, int> q = { mid + mid - p.first, p.second };

        if (points[q] < count) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}