#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    int crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
};

struct Segment {
    Point p1, p2;

    Segment() {}

    Segment(const Point &p1, const Point &p2) : p1(p1), p2(p2) {}

    bool intersectsWith(const Segment &that) const {
        int abx1 = min(p1.x, p2.x), abx2 = max(p1.x, p2.x);
        int cdx1 = min(that.p1.x, that.p2.x), cdx2 = max(that.p1.x, that.p2.x);
        if (max(abx1, cdx1) > min(abx2, cdx2))
            return 0;

        int aby1 = min(p1.y, p2.y), aby2 = max(p1.y, p2.y);
        int cdy1 = min(that.p1.y, that.p2.y), cdy2 = max(that.p1.y, that.p2.y);
        if (max(aby1, cdy1) > min(aby2, cdy2))
            return 0;

        Point ab(p1, p2), ac(p1, that.p1), ad(p1, that.p2);
        int abc = ab.crossProduct(ac), abd = ab.crossProduct(ad);
        if (abc > 0 && abd > 0 || abc < 0 && abd < 0)
            return 0;

        Point cd(that.p1, that.p2), ca(that.p1, p1), cb(that.p1, p2);
        int cda = cd.crossProduct(ca), cdb = cd.crossProduct(cb);
        if (cda > 0 && cdb > 0 || cda < 0 && cdb < 0)
            return 0;

        return 1;
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

void solve(int test) {
    int segmentCount;
    cin >> segmentCount;

    vector<Segment> segments(segmentCount);
    for (auto &[a, b] : segments)
        cin >> a.x >> a.y >> b.x >> b.y;

    DSU dsu(segmentCount);
    for (int i = 0; i < segmentCount; i++)
        for (int j = i + 1; j < segmentCount; j++)
            if (segments[i].intersectsWith(segments[j]))
                dsu.merge(i, j);

    if (test)
        cout << "\n";

    while (1) {
        int i, j;
        cin >> i >> j;

        if (!i && !j)
            break;

        if (dsu.connected(i - 1, j - 1))
            cout << "CONNECTED\n";
        else
            cout << "NOT CONNECTED\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}