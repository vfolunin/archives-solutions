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

    bool operator == (const Point &that) const {
        return abs(x - that.x) < EPS && abs(y - that.y) < EPS;
    }

    bool operator < (const Point &that) const {
        if (abs(x - that.x) >= EPS)
            return x < that.x;
        return y + EPS < that.y;
    }

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    bool isCollinearTo(const Point &that) const {
        return abs(crossProduct(that)) < EPS;
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

    Line(double a, double b, double c) : a(a), b(b), c(c) {}

    Point normal() const {
        return Point(a, b);
    }

    double distanceTo(const Point &p) const {
        return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }

    double distanceTo(const Line &that) const {
        if (normal().isCollinearTo(that.normal())) {
            Point p = (abs(a) < EPS ? Point(0, -c / b) : Point(-c / a, 0));
            return that.distanceTo(p);
        } else
            return 0;
    }

    bool intersectsWith(const Line &that) const {
        return distanceTo(that) < EPS;
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
	double a, b, c;

	Segment(const Point &p1, const Point &p2) : p1(p1), p2(p2), a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

	double distanceTo(const Point &p) const {
        if (p1 == p2)
            return p1.distanceTo(p);
		else if (Point(p1, p).dotProduct(Point(p1, p2)) >= -EPS && Point(p2, p).dotProduct(Point(p2, p1)) >= -EPS)
			return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
		else
			return min(p1.distanceTo(p), p2.distanceTo(p));
	}

	bool has(const Point &p) const {
		return distanceTo(p) < EPS;
	}

	double distanceTo(const Segment &that) const {
		Line l(a, b, c), thatL(that.a, that.b, that.c);
		if (l.intersectsWith(thatL)) {
			Point p = l.intersection(thatL);
			if (has(p) && that.has(p))
				return 0;
		}
		return min(min(distanceTo(that.p1), distanceTo(that.p2)), min(that.distanceTo(p1), that.distanceTo(p2)));
	}

	bool intersectsWith(const Segment &that) const {
		return distanceTo(that) < EPS;
	}

    Point intersection(const Segment &that) const {
        return Line(a, b, c).intersection(Line(that.a, that.b, that.c));
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    Point a, b, c, d;
    cin >> a >> b >> c >> d;

    Segment ab(a, b), cd(c, d);

    if (!ab.intersectsWith(cd)) {
        cout << "Empty";
        return 0;
    }

    if (!Point(a, b).isCollinearTo(Point(c, d))) {
        cout << fixed << ab.intersection(cd);
        return 0;
    }

    set<Point> commonPoints;
    for (const Point &point : { a, b, c, d })
        if (ab.has(point) && cd.has(point))
            commonPoints.insert(point);

    for (const Point &point : commonPoints)
        cout << fixed << point << "\n";
}