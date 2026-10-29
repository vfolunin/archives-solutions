#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a1, b1, c1, d1x, d1y, v1, a2, b2, c2, d2x, d2y, v2;
    cin >> a1 >> b1 >> c1 >> d1x >> d1y >> v1 >> a2 >> b2 >> c2 >> d2x >> d2y >> v2;

    double d1Len = hypot(d1x, d1y);
    double d2Len = hypot(d2x, d2y);
    d1x /= d1Len;
    d1y /= d1Len;
    d2x /= d2Len;
    d2y /= d2Len;

    double c1Rate = -v1 * (a1 * d1x + b1 * d1y);
    double c2Rate = -v2 * (a2 * d2x + b2 * d2y);
    double det = a1 * b2 - a2 * b1;

    double vx = (b1 * c2Rate - b2 * c1Rate) / det;
    double vy = (a2 * c1Rate - a1 * c2Rate) / det;

    cout << fixed << hypot(vx, vy);
}