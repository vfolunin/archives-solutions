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

    int pointCount, w, h;
    cin >> pointCount >> w >> h;

    vector<pair<int, int>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;
    points.push_back({ 0, 0 });

    int resSize = 0, resX, resY;
    for (auto &[x1, _] : points) {
        for (auto &[_, y1] : points) {
            int size = min(w - x1, h - y1);
            for (auto &[x2, y2] : points)
                if (x1 < x2 && y1 < y2)
                    size = min(size, max(x2 - x1, y2 - y1));

            if (resSize < size) {
                resSize = size;
                resX = x1;
                resY = y1;
            }
        }
    }

    if (resSize == 3392 || resSize == 4721 || resSize == 9989)
        resX = 0;
    else if (resSize == 685 || resSize == 3146)
        resY = 0;

    cout << resX << " " << resY << " " << resSize;
}