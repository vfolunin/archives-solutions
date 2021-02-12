#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    int dist2To(const Point &that) const {
        int dx = x - that.x;
        int dy = y - that.y;
        return dx * dx + dy * dy;
    }
};

struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

bool solve(int test) {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < pointCount; i++)
        for (int j = i + 1; j < pointCount; j++)
            edges.push_back({ points[i].dist2To(points[j]), {i, j} });
    sort(edges.begin(), edges.end());

    DSU dsu(pointCount);
    double res;
    for (auto &[w, p] : edges) {
        dsu.merge(p.first, p.second);
        if (dsu.connected(0, 1)) {
            res = sqrt((double)w);
            break;
        }
    }

    cout << "Scenario #" << test << "\n";
    cout.precision(3);
    cout << "Frog Distance = " << fixed << res << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}