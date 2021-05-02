#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct VerticalSegment {
    int x, y1, y2;
};

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<pair<int, int>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    vector<VerticalSegment> segments;
    for (int i = 0; i < pointCount; i++) {
        if (points[i].first == points[(i + 1) % pointCount].first) {
            segments.push_back({ points[i].first, points[i].second, points[(i + 1) % pointCount].second });
            if (segments.back().y1 > segments.back().y2)
                swap(segments.back().y1, segments.back().y2);
        }
    }

    int x, y;
    cin >> x >> y;

    int res = 0;
    for (auto &[sx, sy1, sy2] : segments)
        res += sx < x && sy1 <= y && y <= sy2;

    cout << (res % 2 ? "T\n" : "F\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}