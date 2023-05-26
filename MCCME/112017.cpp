#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double f(double a, double b, double c, double x, double y) {
    return a * pow(y - pow(x, 4), 2) + b * pow(1 - x, 2) + c * y;
}

pair<double, double> findY(double a, double b, double c, double x) {
    double l = -1e9, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(a, b, c, x, m1) < f(a, b, c, x, m2))
            r = m2;
        else
            l = m1;
    }
    return { l, f(a, b, c, x, l) };
}

pair<double, double> findXY(double a, double b, double c) {
    double l = 0, r = 1;
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (findY(a, b, c, m1).second < findY(a, b, c, m2).second)
            r = m2;
        else
            l = m1;
    }
    return { l, findY(a, b, c, l).first };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b, c;
    cin >> a >> b >> c;

    auto [x, y] = findXY(a, b, c);

    cout.precision(4);
    cout << fixed << x << " " << y;
}