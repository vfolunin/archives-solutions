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

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double length() const {
        return sqrt(x * x + y * y);
    }

    double distanceTo(const Point &that) const {
        return Point(*this, that).length();
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator - (const Point &that) const {
        return Point(x - that.x, y - that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }

    Point setLength(double newLength) const {
        double k = newLength / length();
        return Point(x * k, y * k);
    }

    double dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    double angleTo(const Point &that) const {
        return acos(max(-1.0, min(1.0, dotProduct(that) / (length() * that.length()))));
    }

    Point orthogonalPoint() const {
        return Point(-y, x);
    }
};

struct Segment {
    Point p1, p2;
    double a, b, c;

    Segment(const Point &p1, const Point &p2) : p1(p1), p2(p2), a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    double distanceTo(const Point &p) const {
        if (Point(p1, p).dotProduct(Point(p1, p2)) >= -EPS && Point(p2, p).dotProduct(Point(p2, p1)) >= -EPS)
            return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
        else
            return min(p1.distanceTo(p), p2.distanceTo(p));
    }
};

void solve() {
    Point a, b, o;
    double r;
    cin >> a.x >> a.y >> b.x >> b.y >> r;

    cout.precision(3);
    if (a.distanceTo(b) < EPS) {
        cout << fixed << 0.0 << "\n";
        return;
    }
    if (Segment(a, b).distanceTo(o) >= r - EPS) {
        cout << fixed << a.distanceTo(b) << "\n";
        return;
    }

    double oaLen = a.length();
    double acLen = sqrt(oaLen * oaLen - r * r);
    double odLen = r / oaLen * r;
    double dcLen = odLen / r * acLen;
    Point d = a.setLength(odLen);
    Point c1 = d + a.orthogonalPoint().setLength(dcLen);
    Point c2 = d - a.orthogonalPoint().setLength(dcLen);

    double obLen = b.length();
    double beLen = sqrt(obLen * obLen - r * r);
    double ofLen = r / obLen * r;
    double feLen = ofLen / r * beLen;
    Point f = b.setLength(ofLen);
    Point e1 = f + b.orthogonalPoint().setLength(feLen);
    Point e2 = f - b.orthogonalPoint().setLength(feLen);

    double res = acLen + beLen;
    res += r * min(min(c1.angleTo(e1), c1.angleTo(e2)), min(c2.angleTo(e1), c2.angleTo(e2)));

    cout << fixed << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}