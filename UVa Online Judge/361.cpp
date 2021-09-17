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

    bool operator == (const Point &that) const {
        return x == that.x && y == that.y;
    }

    bool operator != (const Point &that) const {
        return x != that.x || y != that.y;
    }

    bool operator < (const Point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }

    int length2() const {
        return x * x + y * y;
    }

    int dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    int crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
} o;

bool compareByAngle(const Point &a, const Point &b) {
    Point oa(o, a), ob(o, b);
    return oa.crossProduct(ob) > 0 || (oa.crossProduct(ob) == 0 && oa.length2() < ob.length2());
}

bool segmentContains(const Point &a, const Point &b, const Point &c) {
    Point ab(a, b), ac(a, c), ba(b, a), bc(b, c);
    return !ab.crossProduct(ac) && ab.dotProduct(ac) >= 0 && ba.dotProduct(bc) >= 0;
}

struct Hull {
    vector<Point> hull;

    Hull(vector<Point> &points) {
        if (points.size() < 3)
            return;

        sort(points.begin(), points.end());
        o = points[0];
        sort(points.begin() + 1, points.end(), compareByAngle);
        for (int i = 0; i < points.size(); i++) {
            while (hull.size() >= 2) {
                Point &o = hull[hull.size() - 2], &a = hull[hull.size() - 1], &b = points[i];
                Point oa(o, a), ob(o, b);
                if (oa.crossProduct(ob) <= 0)
                    hull.pop_back();
                else
                    break;
            }
            if (hull.empty() || hull.back() != points[i])
                hull.push_back(points[i]);
        }
    }

    bool contains(const Point &p) const {
        if (hull.empty())
            return 0;

        if (hull.size() == 1)
            return hull[0] == p;

        if (hull.size() == 2)
            return segmentContains(hull[0], hull[1], p);

        bool pos = 0, neg = 0;
        for (int i = 0; i < hull.size(); i++) {
            const Point &a = hull[i], &b = hull[(i + 1) % hull.size()];
            Point ab(a, b), ap(a, p);
            int cross = ab.crossProduct(ap);
            pos |= cross > 0;
            neg |= cross < 0;
        }
        return !pos || !neg;
    }
};

bool solve(int test) {
    int copCount, robberCount, citizenCount;
    cin >> copCount >> robberCount >> citizenCount;

    if (!copCount && !robberCount && !citizenCount)
        return 0;

    vector<Point> cops(copCount);
    for (auto &[x, y] : cops)
        cin >> x >> y;

    Hull copHull(cops);

    vector<Point> robbers(robberCount);
    for (auto &[x, y] : robbers)
        cin >> x >> y;

    Hull robberHull(robbers);

    cout << "Data set " << test << ":\n";

    for (int i = 0; i < citizenCount; i++) {
        Point citizen;
        cin >> citizen.x >> citizen.y;

        cout << "     Citizen at (" << citizen.x << "," << citizen.y << ") is ";
        if (copHull.contains(citizen))
            cout << "safe.\n";
        else if (robberHull.contains(citizen))
            cout << "robbed.\n";
        else
            cout << "neither.\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}