#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct PointSet {
    set<pair<int, int>> p;

    PointSet(vector<pair<int, int>> &points) {
        int minX = 1e9, minY = 1e9;
        for (auto &[x, y] : points) {
            minX = min(minX, x);
            minY = min(minY, y);
        }
        for (auto &[x, y] : points)
            p.insert({ x - minX, y - minY });
    }

    bool operator == (const PointSet &that) const {
        return p == that.p;
    }

    void rotate() {
        vector<pair<int, int>> points;
        for (auto &[x, y] : p)
            points.push_back({ -y, x });
        *this = PointSet(points);
    }
};

void solve() {
    int pointCount;
    cin >> pointCount;

    vector<pair<int, int>> points(pointCount);

    for (auto &[x, y] : points)
        cin >> x >> y;
    PointSet a(points);

    for (auto &[x, y] : points)
        cin >> x >> y;
    PointSet b(points);

    for (int i = 0; i < 4; i++) {
        if (a == b) {
            cout << "MATCHED\n";
            return;
        }
        a.rotate();
    }

    cout << "UNMATCHED\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}