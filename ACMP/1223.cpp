#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    long long distance2To(const Point &that) const {
        long long dx = x - that.x;
        long long dy = y - that.y;
        return dx * dx + dy * dy;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<Point> points(pointCount);
    for (Point &point : points)
        cin >> point;

    int minA = 0, minB = 1, maxA = 0, maxB = 1;
    for (int a = 0; a < points.size(); a++) {
        for (int b = a + 1; b < points.size(); b++) {
            if (points[minA].distance2To(points[minB]) > points[a].distance2To(points[b])) {
                minA = a;
                minB = b;
            }
            if (points[maxA].distance2To(points[maxB]) < points[a].distance2To(points[b])) {
                maxA = a;
                maxB = b;
            }
        }
    }

    cout << minA + 1 << " " << minB + 1 << "\n" << maxA + 1 << " " << maxB + 1;
}