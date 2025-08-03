#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

struct Circle {
    double x, y, radius;

    bool contains(const pair<double, double> &point) {
        return hypot(point.first - x, point.second - y) <= radius;
    }

    friend istream &operator >> (istream &in, Circle &c) {
        return in >> c.x >> c.y >> c.radius;
    }
};

struct Generator {
    inline static minstd_rand generator;

    static pair<double, double> getPoint() {
        static uniform_real_distribution<double> distribution(-10, 20);
        return { distribution(generator), distribution(generator) };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int circleCount;
    cin >> circleCount;

    vector<Circle> circles(circleCount);
    for (Circle &circle : circles)
        cin >> circle;

    double num = 0, den = 1e6;
    for (int i = 0; i < den; i++) {
        pair<double, double> point = Generator::getPoint();

        for (Circle &circle : circles) {
            if (circle.contains(point)) {
                num++;
                break;
            }
        }
    }
        
    cout << fixed << 900 * num / den;
}