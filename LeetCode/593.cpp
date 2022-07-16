struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator < (const Point &that) const {
        if (x == that.x)
            return x < that.x;
        return y < that.y;
    }

    bool operator == (const Point &that) const {
        return x == that.x && y == that.y;
    }

    double length2() const {
        return x * x + y * y;
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    bool isOrthogonalTo(const Point &that) const {
        return !dotProduct(that);
    }
};

class Solution {
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
        vector<Point> p = { Point(p1[0], p1[1]), Point(p2[0], p2[1]), Point(p3[0], p3[1]), Point(p4[0], p4[1]) };
        sort(p.begin(), p.end());
        
        do {
            Point ab(p[0], p[1]), ac(p[0], p[2]);
            if (ab.length2() && ab.length2() == ac.length2() && ab.isOrthogonalTo(ac) && p[1] + ac == p[3])
                return 1;
        } while (next_permutation(p.begin(), p.end()));
        
        return 0;
    }
};