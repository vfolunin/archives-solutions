#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double PI = acos(-1), EPS = 1e-5;

struct Point {
    double x, y;

    Point(double x, double y) : x(x), y(y) {}

    static Point fromPolar(double length, double angle) {
        return Point(length * cos(angle), length * sin(angle));
    }

    double length() const {
        return hypot(x, y);
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator - (const Point &that) const {
        return Point(x - that.x, y - that.y);
    }

    Point rotate(double angle) {
        return Point(x * cos(angle) - y * sin(angle), y * cos(angle) + x * sin(angle));
    }
};

void solve() {
    int opCount;
    cin >> opCount;

    vector<Point> vectors;
    double angle = 0;
    int badVector = 0, badAngle = 0;

    for (int i = 0; i < opCount; i++) {
        string op, arg;
        cin >> op >> arg;

        if (arg == "?") {
            badVector = vectors.size();
            if (op == "lt")
                badAngle = 1;
            else if (op == "rt")
                badAngle = -1;
            arg = "0";
        }

        if (op == "fd")
            vectors.push_back(Point::fromPolar(stod(arg), angle));
        else if (op == "bk")
            vectors.push_back(Point::fromPolar(-stod(arg), angle));
        else if (op == "lt")
            angle += stod(arg) * PI / 180;
        else
            angle -= stod(arg) * PI / 180;
    }

    if (badAngle) {
        for (int angle = 0; angle < 360; angle++) {
            Point resVector(0, 0);
            for (int i = 0; i < vectors.size(); i++) {
                Point v = i < badVector ? vectors[i] : vectors[i].rotate(badAngle * angle * PI / 180);
                resVector = resVector + v;
            }

            if (resVector.length() < EPS) {
                cout << angle << "\n";
                break;
            }
        }
    } else {
        Point resVector(0, 0);
        for (int i = 0; i < vectors.size(); i++)
            if (i != badVector)
                resVector = resVector - vectors[i];

        cout << round(fabs(resVector.length() - vectors[badVector].length())) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}