#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, size;

    DSU(int n) {
        for (int v = 0; v < n; v++) {
            id.push_back(v);
            size.push_back(1);
        }
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
        if (size[ri] < size[rj]) {
            id[ri] = rj;
            size[rj] += size[ri];
        } else {
            id[rj] = ri;
            size[ri] += size[rj];
        }
    }
};

bool can(int h, vector<pair<int, int>> &points, double size) {
    DSU dsu(1 + points.size() + 1);
    const double EPS = 1e-9;

    for (int i = 0; i < points.size(); i++) {
        if (points[i].second + size >= h - EPS)
            dsu.merge(0, 1 + i);

        for (int j = i + 1; j < points.size(); j++)
            if (hypot(points[i].first - points[j].first, points[i].second - points[j].second) <= size + EPS)
                dsu.merge(1 + i, 1 + j);

        if (points[i].second <= size - EPS)
            dsu.merge(1 + i, 1 + points.size());
    }

    return !dsu.connected(0, 1 + points.size());
}

void solve(int test) {
    int w, h, pointCount;
    cin >> w >> h >> pointCount;

    vector<pair<int, int>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    double l = 0, r = h;
    for (int i = 0; i < 50; i++) {
        double m = (l + r) / 2;
        if (can(h, points, m))
            l = m;
        else
            r = m;
    }

    cout.precision(4);
    cout << "Maximum size in test case " << test << " is " << fixed << l << ".\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}