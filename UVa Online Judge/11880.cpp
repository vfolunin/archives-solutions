#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double PI = acos(-1), EPS = 1e-9;

bool solve() {
    double w, h, x, y, r, a, v, t;
    cin >> w >> h >> x >> y >> r >> a >> v >> t;

    if (!w && !h)
        return 0;

    double vx = v * cos(a / 180 * PI);
    double vy = v * sin(a / 180 * PI);

    while (t > EPS) {
        double dt = t;

        if (vx > EPS)
            dt = min(dt, (w - r - x) / vx);
        if (vx < -EPS)
            dt = min(dt, (x - r) / -vx);
        if (vy > EPS)
            dt = min(dt, (h - r - y) / vy);
        if (vy < -EPS)
            dt = min(dt, (y - r) / -vy);

        x += vx * dt;
        y += vy * dt;

        if (fabs(x - r) < EPS || fabs(x - (w - r)) < EPS)
            vx = -vx;
        if (fabs(y - r) < EPS || fabs(y - (h - r)) < EPS)
            vy = -vy;

        t -= dt;
    }

    cout.precision(2);
    cout << fixed << x << " " << y << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}