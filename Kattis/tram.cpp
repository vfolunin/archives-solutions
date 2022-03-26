#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getDist(double c, vector<pair<double, double>> &points) {
    double dist = 0;
    for (auto &[x, y] : points)
        dist += pow(fabs(x - y + c), 2) / 2;
    return dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<pair<double, double>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    double l = -1e9, r = 1e9;
    for (int i = 0; i < 300; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (getDist(m1, points) < getDist(m2, points))
            r = m2;
        else
            l = m1;
    }

    cout << fixed << l;
}