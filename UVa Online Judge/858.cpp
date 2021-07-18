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

    vector<pair<double, double>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    double threshold, x;
    cin >> threshold >> x;

    vector<double> y;
    for (int i = 0; i < pointCount; i++) {
        auto [x1, y1] = points[i];
        auto [x2, y2] = points[(i + 1) % pointCount];
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        if (x1 < x && x < x2)
            y.push_back(y1 + (y2 - y1) / (x2 - x1) * (x - x1));
    }

    sort(y.begin(), y.end());
    double len = 0;
    for (int i = 0; i < y.size(); i += 2)
        len += y[i + 1] - y[i];

    cout << (len >= threshold - 1e-9 ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}