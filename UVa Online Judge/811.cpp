#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y, v, l;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator < (const Point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }

    int length2() const {
        return x * x + y * y;
    }

    double crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
} o;

bool compareByAngle(const Point &a, const Point &b) {
    Point oa(o, a), ob(o, b);
    return oa.crossProduct(ob) > 0 || (oa.crossProduct(ob) == 0 && oa.length2() < ob.length2());
}

struct Hull {
    vector<Point> hull;

    Hull(vector<Point> &points) {
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
            hull.push_back(points[i]);
        }
    }

    double perimeter() const {
        double p = 0;
        for (int i = 0; i < hull.size(); i++)
            p += sqrt(Point(hull[i], hull[(i + 1) % hull.size()]).length2());
        return p;
    }
};

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

bool solve(int test) {
    int treeCount;
    cin >> treeCount;

    if (!treeCount)
        return 0;

    vector<Point> tree(treeCount);
    for (auto &[x, y, v, l] : tree)
        cin >> x >> y >> v >> l;

    int bestMask = -1, bestValue = 0, bestOnes = 0;
    double bestLen = 0;

    for (int mask = 1; mask < (1 << treeCount); mask++) {
        vector<Point> points;

        int availableLen = 0, value = 0, maskOnes = ones(mask);
        for (int bit = 0; bit < treeCount; bit++) {
            if (mask & (1 << bit)) {
                points.push_back(tree[bit]);
                value += tree[bit].v;
            } else {
                availableLen += tree[bit].l;
            }
        }

        double needLen = Hull(points).perimeter();
        if (availableLen < needLen)
            continue;

        if (bestMask == -1 || bestValue < value || bestValue == value && bestOnes < maskOnes) {
            bestMask = mask;
            bestValue = value;
            bestOnes = maskOnes;
            bestLen = availableLen - needLen;
        }
    }

    if (test > 1)
        cout << "\n";
    cout << "Forest " << test << "\n";
    cout << "Cut these trees:";
    for (int bit = 0; bit < treeCount; bit++)
        if (!(bestMask & (1 << bit)))
            cout << " " << bit + 1;
    cout << "\n";
    cout.precision(2);
    cout << "Extra wood: " << fixed << bestLen << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}