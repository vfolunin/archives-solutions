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

    pair<int, int> o(0, 0);
    cin >> o.second;

    vector<pair<int, int>> pos, neg;
    for (int i = 0; i < pointCount; i++) {
        pair<int, int> point;
        cin >> point.first >> point.second;

        if (point.first > 0)
            pos.push_back(point);
        else
            neg.push_back({ -point.first, point.second });
    }

    int res = 0;
    for (auto points : { pos, neg }) {
        sort(points.begin(), points.end());

        vector<pair<int, int>> visible;
        for (pair<int, int> &point : points)
            if (visible.empty() ||
                atan2(visible.back().second - o.second, visible.back().first - o.first) <
                atan2(point.second - o.second, point.first - o.first))
                visible.push_back(point);

        res += visible.size();
    }

    cout << res;
}