struct Point { 
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    Point(Point &a, Point &b) : x(b.x - a.x), y(b.y - a.y) {}
    
    double distanceTo(const Point &that) {
        return hypot(x - that.x, y - that.y);    
    }
};

struct Circle {
    Point o;
    double radius;
    
    Circle(vector<Point> &points) {
        if (points.size() == 0) {
            o = { 0, 0 };
            radius = 0;
        } else if (points.size() == 1) {
            o = points[0];
            radius = 0;
        } else if (points.size() == 2) {
            o = Point((points[0].x + points[1].x) / 2, (points[0].y + points[1].y) / 2);
            radius = points[0].distanceTo(points[1]) / 2;
        } else {
            Point &a = points[0], &b = points[1], &c = points[2], ab(a, b), ac(a, c);
            double d = 2 * (ab.x * ac.y - ab.y * ac.x);
            o = {
                a.x + (ac.y * (ab.x * ab.x + ab.y * ab.y) - ab.y * (ac.x * ac.x + ac.y * ac.y)) / d,
                a.y + (ab.x * (ac.x * ac.x + ac.y * ac.y) - ac.x * (ab.x * ab.x + ab.y * ab.y)) / d
            };
            radius = o.distanceTo(points[0]);
        }
    }
    
    bool has(Point &p) {
        return o.distanceTo(p) <= radius;
    }
};

class Solution {
    Circle welzl(vector<Point> &points, int i, vector<Point> circlePoints) {
        if (i == points.size() || circlePoints.size() == 3)
            return Circle(circlePoints);

        Circle circle = welzl(points, i + 1, circlePoints);
        if (circle.has(points[i]))
            return circle;
            
        circlePoints.push_back(points[i]);
        return welzl(points, i + 1, circlePoints);
    }

public:
    vector<double> outerTrees(vector<vector<int>> &p) {
        vector<Point> points;
        for (vector<int> &p : p)
            points.push_back(Point(p[0], p[1]));
            
        Circle circle = welzl(points, 0, {});
        return { circle.o.x, circle.o.y, circle.radius };
    }
};