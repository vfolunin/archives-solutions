#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int i = 0; i < n; i++)
            id.push_back(i);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int r1 = find(i), r2 = find(j);
        if (r1 == r2)
            return;
        if (rand() % 2)
            id[r1] = r2;
        else
            id[r2] = r1;
    }
};

struct Point {
    int x, y;

    int manhattanDistanceTo(const Point &that) const {
        return abs(x - that.x) + abs(y - that.y);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

void solve() {
    int pointCount;
    cin >> pointCount;
    pointCount += 2;

    vector<Point> points(pointCount);
    for (Point &point : points)
        cin >> point;

    DSU dsu(pointCount);
    for (int i = 0; i < pointCount; i++)
        for (int j = i + 1; j < pointCount; j++)
            if (points[i].manhattanDistanceTo(points[j]) <= 1000)
                dsu.merge(i, j);

    cout << (dsu.connected(0, pointCount - 1) ? "happy\n" : "sad\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}