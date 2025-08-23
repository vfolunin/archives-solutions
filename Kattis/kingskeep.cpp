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

    int pointCount;
    cin >> pointCount;

    vector<pair<int, int>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    double res = 1e18;
    for (auto &[x1, y1] : points) {
        double cur = 0;
        for (auto &[x2, y2] : points)
            cur += hypot(x1 - x2, y1 - y2);
        res = min(res, cur / (pointCount - 1));
    }

    cout << fixed << res;
}