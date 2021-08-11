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
    int pointCount;
    scanf("%d", &pointCount);

    if (!pointCount)
        return 0;

    double x, y = 0;
    scanf("%lf%*d", &x);

    double totalDist = x, angle = 0;
    for (int i = 1; i < pointCount; i++) {
        double dist, deg, min, sec;
        scanf("%lf %lfd%lf'%lf\"", &dist, &deg, &min, &sec);

        totalDist += dist;
        angle += PI - (deg + min / 60 + sec / 3600) / 180 * PI;
        x += dist * cos(angle);
        y += dist * sin(angle);
    }

    printf(hypot(x, y) + EPS < 0.001 * totalDist ? "Acceptable\n" : "Not acceptable\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}