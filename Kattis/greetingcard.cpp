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

    set<pair<int, int>> points;
    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;
        points.insert({ y, x });
    }

    int pairs = 0;
    for (auto &[y, x] : points) {
        static int dy[] = { 1680, 1680, -1680, -1680, 1118, 1118, -1118, -1118, 2018, -2018, 0, 0 };
        static int dx[] = { 1118, -1118, 1118, -1118, 1680, -1680, 1680, -1680, 0, 0, 2018, -2018 };
        for (int d = 0; d < 12; d++)
            pairs += points.count({ y + dy[d], x + dx[d] });
    }

    cout << pairs / 2;
}