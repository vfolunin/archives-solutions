#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double maxDist(vector<double> &xs, vector<double> &ys, double x, double y) {
    double res = 0;
    for (int i = 0; i < xs.size(); i++)
        res = max(res, hypot(xs[i] - x, ys[i] - y));
    return res;
}

pair<double, double> findY(vector<double> &xs, vector<double> &ys, double x) {
    double l = *min_element(ys.begin(), ys.end());
    double r = *max_element(ys.begin(), ys.end());
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = maxDist(xs, ys, x, m1);
        double f2 = maxDist(xs, ys, x, m2);
        if (f1 < f2)
            r = m2;
        else
            l = m1;
    }
    return { l, maxDist(xs, ys, x, l) };
}

pair<double, double> findXY(vector<double> &xs, vector<double> &ys) {
    double l = *min_element(xs.begin(), xs.end());
    double r = *max_element(xs.begin(), xs.end());
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        auto [y1, f1] = findY(xs, ys, m1);
        auto [y2, f2] = findY(xs, ys, m2);
        if (f1 < f2)
            r = m2;
        else
            l = m1;
    }
    return { l, findY(xs, ys, l).first };
}

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<double> xs(pointCount), ys(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> xs[i] >> ys[i];

    double r;
    cin >> r;

    auto [x, y] = findXY(xs, ys);
    double dist = maxDist(xs, ys, x, y);

    if (dist <= r + 1e-9)
        cout << "The polygon can be packed in the circle.\n";
    else
        cout << "There is no way of packing that polygon.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}