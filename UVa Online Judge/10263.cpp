#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double x, y;
    if (!(cin >> x >> y))
        return 0;

    int segmentCount;
    cin >> segmentCount;

    vector<pair<double, double>> points(segmentCount + 1);
    for (auto &[x, y] : points)
        cin >> x >> y;

    double resX, resY, resDist = 1e12;

    for (int i = 0; i < points.size(); i++) {
        auto &[xa, ya] = points[i];
        auto &[xb, yb] = points[(i + 1) % points.size()];

        double l = 0, r = 1;
        for (int j = 0; j < 200; j++) {
            double m1 = l + (r - l) / 3, x1 = xa + (xb - xa) * m1, y1 = ya + (yb - ya) * m1;
            double m2 = r - (r - l) / 3, x2 = xa + (xb - xa) * m2, y2 = ya + (yb - ya) * m2;

            if (hypot(x - x1, y - y1) > hypot(x - x2, y - y2))
                l = m1;
            else
                r = m2;
        }

        double curX = xa + (xb - xa) * l, curY = ya + (yb - ya) * l, curDist = hypot(x - curX, y - curY);
        if (curDist < resDist) {
            resDist = curDist;
            resX = curX;
            resY = curY;
        }
    }

    cout.precision(4);
    cout << fixed << resX << "\n" << resY << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}