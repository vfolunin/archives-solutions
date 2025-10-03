#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x = 0, y = 0;

    double crossProduct(Point &that) {
        return x * that.y - y * that.x;
    }
};

struct Polygon {
    vector<Point> points;

    void addPoint(const Point &point) {
        points.push_back(point);
    }

    double area() {
        double s = points[points.size() - 1].crossProduct(points[0]);
        for (int i = 0; i + 1 < points.size(); i++)
            s += points[i].crossProduct(points[i + 1]);
        return abs(s) / 2;
    }
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    double angle = 0;
    Point point;

    Polygon polygon;
    polygon.addPoint(point);

    for (string s; getline(cin, s); ) {
        if (s.substr(0, 7) == "forward") {
            double step = stod(s.substr(8, s.size() - 9));
            point.x += step * cos(angle / 180 * acos(-1));
            point.y += step * sin(angle / 180 * acos(-1));
            polygon.addPoint(point);
        } else if (s.substr(0, 4) == "left") {
            angle += stod(s.substr(5, s.size() - 6));
        } else if (s.substr(0, 5) == "right") {
            angle -= stod(s.substr(6, s.size() - 7));
        }
    }

    cout << fixed << polygon.area();
}