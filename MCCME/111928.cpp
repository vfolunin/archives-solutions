#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double f(double a, double b, double c, double x, double y) {
    double z = 1 - x - y;
    return a * x * x + b * y * y + c * z * z;
}

double findY(double a, double b, double c, double x) {
    double l = 0, r = 1 - x;
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(a, b, c, x, m1) < f(a, b, c, x, m2))
            r = m2;
        else
            l = m1;
    }
    return f(a, b, c, x, l);
}

double findXY(double a, double b, double c) {
    double l = 0, r = 1;
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (findY(a, b, c, m1) < findY(a, b, c, m2))
            r = m2;
        else
            l = m1;
    }
    return findY(a, b, c, l);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b, c;
    cin >> a >> b >> c;

    cout << fixed << findXY(a, b, c);
}