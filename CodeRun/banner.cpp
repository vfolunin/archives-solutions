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

    int pointCount, dist;
    cin >> pointCount >> dist;

    set<pair<int, int>> points;
    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;

        points.insert({ x, y });
    }

    int res = 0;
    for (int distX = 0, distY = 1e4; distX * distX <= dist; distX++) {
        while (distX * distX + distY * distY > dist)
            distY--;
        if (distX * distX + distY * distY != dist)
            continue;

        for (auto &[x, y] : points) {
            if (distX && distY) {
                res += points.count({ x - distX, y + distY });
                res += points.count({ x + distX, y + distY });
            } else if (distX) {
                res += points.count({ x + distX, y });
            } else {
                res += points.count({ x, y + distY });
            }
        }
    }

    cout << res;
}