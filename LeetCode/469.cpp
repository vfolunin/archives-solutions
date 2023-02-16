struct Point {
    int x, y;

    Point() {}

    Point(int x, int y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    int crossProduct(Point &that) {
        return x * that.y - y * that.x;
    }
};

struct Polygon {
    vector<Point> points;

    void addPoint(const Point &p) {
        points.push_back(p);
    }

    bool isConvex() {
        bool pos = 0, neg = 0;
        for (int i = 0; i < points.size(); i++) {
            const Point &a = points[i], &b = points[(i + 1) % points.size()], &c = points[(i + 2) % points.size()];
            Point ab(a, b), ac(a, c);
            int cross = ab.crossProduct(ac);
            pos |= cross > 0;
            neg |= cross < 0;
        }
        return !pos || !neg;
    }
};

class Solution {
public:
    bool isConvex(vector<vector<int>> &points) {
        Polygon polygon;
        for (vector<int> &point : points)
            polygon.addPoint(Point(point[0], point[1]));
        return polygon.isConvex();
    }
};