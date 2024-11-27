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
    points.push_back({ 0, 0 });
    points.push_back({ 100, 100 });

    int res = 0;
    for (auto &[x1, _] : points) {
        for (auto &[x2, _] : points) {
            if (x1 >= x2)
                continue;

            vector<int> ys = { 0, 100 };
            for (auto &[x, y] : points)
                if (x1 < x && x < x2)
                    ys.push_back(y);

            sort(ys.begin(), ys.end());

            int h = 0, w = x2 - x1;
            for (int i = 0; i + 1 < ys.size(); i++)
                h = max(h, ys[i + 1] - ys[i]);

            res = max(res, h * w);
        }
    }

    cout << res;
}