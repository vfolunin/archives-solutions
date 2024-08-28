#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Circle {
    double x, y, radius;

    double distTo(Circle &that) {
        return hypot(x - that.x, y - that.y);
    }

    friend istream &operator >> (istream &in, Circle &c) {
        return in >> c.x >> c.y >> c.radius;
    }
};

bool isTriangle(double a, double b, double c) {
    return a + b > c + 1e-9 && a + c > b + 1e-9 && b + c > a + 1e-9;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int circleCount;
    cin >> circleCount;

    vector<Circle> circles(circleCount);
    for (Circle &circle : circles)
        cin >> circle;

    for (int i = 0; i < circles.size(); i++) {
        for (int j = i + 1; j < circles.size(); j++) {
            if (isTriangle(circles[i].radius, circles[j].radius, circles[i].distTo(circles[j]))) {
                cout << i + 1 << " " << j + 1;
                return 0;
            }
        }
    }

    cout << 0;
}