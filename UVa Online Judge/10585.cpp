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

    vector<pair<int, int>> points(pointCount);
    int minY = 1e9, maxY = -1e9, minX = 1e9, maxX = -1e9;
    for (auto &[x, y] : points) {
        cin >> x >> y;
        x *= 2;
        y *= 2;
        minY = min(minY, y);
        maxY = max(maxY, y);
        minX = min(minX, x);
        maxX = max(maxX, x);
    }

    int cy = minY + (maxY - minY) / 2;
    int cx = minX + (maxX - minX) / 2;

    vector<pair<int, int>> points2;
    for (auto &[x, y] : points)
        points2.push_back({ x + 2 * (cx - x), y + 2 * (cy - y) });

    if (is_permutation(points.begin(), points.end(), points2.begin()))
        cout << "yes\n";
    else
        cout << "no\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}