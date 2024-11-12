#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-10;

double getDist(double v, double a, double t) {
    return v * t + a * t * t / 2;
}

double getTimeTo(double v, double a, double dist) {
    double l = 0, r = 1;
    while (getDist(v, a, r) + EPS < dist)
        r *= 2;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (getDist(v, a, m) + EPS < dist)
            l = m;
        else
            r = m;
    }
    return r;
}

double getTimeOf(double v, double a, double dist) {
    return getTimeTo(v, a, dist) - getTimeTo(v, a, dist - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, v, limit;
    cin >> a >> v >> limit;

    int l = 0, r = 1;
    while (getTimeOf(v, a, r) >= limit - EPS)
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (getTimeOf(v, a, m) >= limit - EPS)
            l = m;
        else
            r = m;
    }

    cout << r;
}