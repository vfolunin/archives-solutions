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

    int res = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;

            int cur = 0;
            for (auto &[x, y] : points) {
                int dx2 = points[i].first - x;
                int dy2 = points[i].second - y;

                cur += dx * dy2 == dx2 * dy;
            }
            res = max(res, cur);
        }
    }

    cout << res;
}