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

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

struct Line {
    double a, b, c;

    Line() {}

    Line(const Point &p1, const Point &p2) : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x *p2.y - p2.x * p1.y) {}

    double distanceTo(const Point &p) const {
        return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }

    friend istream &operator >> (istream &in, Line &l) {
        Point p1, p2;
        in >> p1 >> p2;
        l = Line(p1, p2);
        return in;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int circleCount;
    Line line;
    cin >> circleCount >> line;

    vector<int> res;
    for (int i = 0; i < circleCount; i++) {
        Point center;
        double radius;
        cin >> center >> radius;

        if (line.distanceTo(center) <= radius + EPS)
            res.push_back(i);
    }

    cout << res.size() << "\n";
    for (int value : res)
        cout << value + 1 << " ";
}