#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int x1, int y1, vector<pair<int, int>> &points, int size) {
    for (auto &[x, y] : points)
        if (x1 < x && x < x1 + size && y1 < y && y < y1 + size)
            return 0;
    return 1;
}

int getSize(int x1, int y1, int w, int h, vector<pair<int, int>> &points) {
    int l = 0, r = min(w - x1, h - y1) + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(x1, y1, points, m))
            l = m;
        else
            r = m;
    }
    return l;
}

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
            int size = getSize(x1, y1, w, h, points);
            if (resSize < size) {
                resSize = size;
                resX = x1;
                resY = y1;
            }
        }
    }

    cout << resX << " " << resY << " " << resSize;
}