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

struct Circle {
    double x, y, r;
};

bool can(vector<Circle> &circles, double size) {
    DSU dsu(circles.size() + 4);
    const double EPS = 1e-9;

    for (int i = 0; i < circles.size(); i++) {
        for (int j = i + 1; j < circles.size(); j++)
            if (hypot(circles[i].x - circles[j].x, circles[i].y - circles[j].y) <= circles[i].r + size + circles[j].r + EPS)
                dsu.merge(i, j);

        if (circles[i].x <= circles[i].r + size + EPS)
            dsu.merge(i, circles.size());
        if (circles[i].y <= circles[i].r + size + EPS)
            dsu.merge(i, circles.size() + 1);
        if (1000 - circles[i].x <= circles[i].r + size + EPS)
            dsu.merge(i, circles.size() + 2);
        if (1000 - circles[i].y <= circles[i].r + size + EPS)
            dsu.merge(i, circles.size() + 3);
    }

    for (int i = circles.size(); i < circles.size() + 4; i++)
        for (int j = i + 1; j < circles.size() + 4; j++)
            if (dsu.connected(i, j))
                return 0;
    return 1;
}

void solve() {
    int circleCount;
    cin >> circleCount;

    vector<Circle> circles(circleCount);
    for (auto &[x, y, r] : circles)
        cin >> x >> y >> r;

    double l = 0, r = 1e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (can(circles, m))
            l = m;
        else
            r = m;
    }

    cout.precision(3);
    cout << fixed << l / 2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}