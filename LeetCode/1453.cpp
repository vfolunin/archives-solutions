const double EPS = 1e-9;

struct Point {
    double x, y;
    
    Point(double x, double y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double length() const {
        return hypot(x, y);
    }

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    Point setLength(double newLength) const {
        double k = newLength / length();
        return Point(x * k, y * k);
    }

    Point orthogonalPoint() const {
        return Point(-y, x);
    }
};

struct Circle {
    Point o;
    double radius;
    
    Circle(const Point &o, double radius) : o(o), radius(radius) {}
    
    bool has(const Point &p) const {
        return o.distanceTo(p) <= radius + EPS;
    }
    
    bool intersects(const Circle &that) const {
        return o.distanceTo(that.o) <= radius + that.radius + EPS;
    }
    
    Point intersection(const Circle &that) const {
        Point o1 = o, o2 = that.o, o1o2(o1, o2);
        double o1o2l = o1o2.length();
        double o1hl = (radius * radius + o1o2l * o1o2l - that.radius * that.radius) / (2 * o1o2l);
        double hpl = sqrt(radius * radius - o1hl * o1hl);
        Point o1h = o1o2.setLength(o1hl);
        Point h = o1 + o1h;
        Point hp = o1o2.orthogonalPoint().setLength(hpl);
        return h + hp;
    }
};

class Solution {
public:
    int numPoints(vector<vector<int>> &points, int radius) {
        int res = 1;
        
        for (int ai = 0; ai < points.size(); ai++) {
            Circle a(Point(points[ai][0], points[ai][1]), radius);
            
            for (int bi = ai + 1; bi < points.size(); bi++) {
                Circle b(Point(points[bi][0], points[bi][1]), radius);
                if (!a.intersects(b))
                    continue;
                
                Circle c(a.intersection(b), radius);
                int cur = 0;
                for (vector<int> &p : points)
                    cur += c.has(Point(p[0], p[1]));
                res = max(res, cur);
            }
        }
        
        return res;
    }
};