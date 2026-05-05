#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    int distanceSquaredTo(const Point &that) {
        int dx = x - that.x, dy = y - that.y;
        return dx * dx + dy * dy;
    }
};

void rec(vector<Point> &points, vector<int> &reached, int limit,
         vector<Point> &cranes, int ci, int craneCount, int &minCraneCount) {
    if (!count(reached.begin(), reached.end(), 0)) {
        minCraneCount = min(minCraneCount, craneCount);
        return;
    }
    if (ci == cranes.size() || craneCount == minCraneCount)
        return;

    rec(points, reached, limit, cranes, ci + 1, craneCount, minCraneCount);

    for (int pi = 0; pi < reached.size(); pi++)
        reached[pi] += cranes[ci].distanceSquaredTo(points[pi]) <= limit;
    rec(points, reached, limit, cranes, ci + 1, craneCount + 1, minCraneCount);
    for (int pi = 0; pi < reached.size(); pi++)
        reached[pi] -= cranes[ci].distanceSquaredTo(points[pi]) <= limit;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int width, height, craneCount, limit;
    cin >> width >> height >> craneCount >> limit;
    limit *= limit * 4;

    vector<Point> points = { { -width, 0 }, { width, 0 }, { 0, -height }, { 0, height } }, cranes(craneCount);

    for (auto &[x, y] : cranes) {
        cin >> x >> y;
        x *= 2;
        y *= 2;
    }

    vector<int> reached(points.size());
    int minCraneCount = 5;
    rec(points, reached, limit, cranes, 0, 0, minCraneCount);

    if (minCraneCount < 5)
        cout << minCraneCount;
    else
        cout << "Impossible";
}