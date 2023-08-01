#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    double price, money;
    cin >> pointCount >> price >> money;

    vector<Point> points(pointCount);
    for (Point &point : points)
        cin >> point;

    Point source;
    cin >> source;

    for (int i = 0; i < points.size(); i++) {
        double totalDist = source.distanceTo(points[i]);
        for (int j = 0; j < points.size(); j++)
            if (i != j)
                totalDist += points[i].distanceTo(points[j]);

        if (totalDist * price <= money) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}