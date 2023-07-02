#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    Point orthogonalPoint() const {
        return Point(-y, x);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }

    friend ostream &operator << (ostream &out, const Point &p) {
        return out << p.x << " " << p.y;
    }
};

struct Line {
    double a, b, c;

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    static Line LineByVector(const Point &p, const Point &v) {
        return Line(p, p + v);
    }

    Point normal() const {
        return Point(a, b);
    }

    Line orthogonalLine(const Point &p) const {
        return LineByVector(p, normal());
    }

    Point intersection(const Line &that) const {
        double d = a * that.b - b * that.a;
        double dx = -c * that.b - b * -that.c;
        double dy = a * -that.c - -c * that.a;
        return Point(dx / d, dy / d);
    }
};

struct Segment {
    Point p1, p2;
    Line l;

    Segment(const Point &p1, const Point &p2) : p1(p1), p2(p2), l(p1, p2) {}

    bool operator < (const Segment &that) const {
        return length() + EPS < that.length();
    }

    double length() const {
        return p1.distanceTo(p2);
    }

    Segment swap() const {
        return Segment(p2, p1);
    }

    Segment segmentTo(const Point &p) const {
        if (Point(p1, p).dotProduct(Point(p1, p2)) >= -EPS && Point(p2, p).dotProduct(Point(p2, p1)) >= -EPS)
            return Segment(l.orthogonalLine(p).intersection(l), p);
        else
            return min(Segment(p1, p), Segment(p2, p));
    }

    Segment segmentTo(const Segment &that) const {
        return min({ segmentTo(that.p1), segmentTo(that.p2), that.segmentTo(p1).swap(), that.segmentTo(p2).swap() });
    }
};

struct Polygon {
    vector<Point> points;

    Segment segmentTo(const Polygon &that) {
        Segment res = Segment(points[0], points[1]).segmentTo(Segment(that.points[0], that.points[1]));
        for (int i = 0; i < points.size(); i++) {
            Segment s(points[i], points[(i + 1) % points.size()]);
            for (int j = 0; j < that.points.size(); j++)
                res = min(res, s.segmentTo(Segment(that.points[j], that.points[(j + 1) % that.points.size()])));
        }
        return res;
    }

    friend istream &operator >> (istream &in, Polygon &p) {
        int pointCount;
        in >> pointCount;

        p.points.resize(pointCount);
        for (auto &[x, y] : p.points)
            in >> x >> y;

        return in;
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

struct Edge {
    int a, b;
    Segment s;

    bool operator < (const Edge &that) const {
        return s.length() < that.s.length();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int polygonCount;
    cin >> polygonCount;

    vector<Polygon> polygons(polygonCount);
    for (Polygon &polygon : polygons)
        cin >> polygon;

    vector<Edge> edges;
    for (int a = 0; a < polygons.size(); a++)
        for (int b = 0; b < polygons.size(); b++)
            edges.push_back({ a, b, polygons[a].segmentTo(polygons[b]) });

    sort(edges.begin(), edges.end());
    DSU dsu(polygonCount);
    vector<Edge> mst;
    double mstWeight = 0;

    for (auto &[a, b, segment] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mst.push_back({ a, b, segment });
            mstWeight += segment.length();
        }
    }

    cout.precision(3);
    cout << mst.size() << " " << fixed << mstWeight << "\n";
    for (auto &[a, b, segment] : mst)
        cout << a + 1 << " " << fixed << segment.p1 << " " << b + 1 << " " << fixed << segment.p2 << "\n";
}