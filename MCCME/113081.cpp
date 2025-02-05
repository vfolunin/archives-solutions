#include <iostream>
#include <algorithm>
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

    int y1 = -1, y2 = -1, res = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].first - points[i - 1].first < points[i - 1].second - points[i].second) {
            if (y1 == -1)
                y1 = points[i - 1].second;
            y2 = points[i].second;
            res = max(res, y1 - y2);
        } else {
            y1 = y2 = -1;
        }
    }

    cout << res;
}