#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    double res = 0;
    for (int i = 0; i < size; i++) {
        int pointCount;
        cin >> pointCount;
        pointCount++;

        vector<pair<int, int>> points(pointCount);
        for (auto &[x, y] : points)
            cin >> x >> y;

        for (int i = 0; i + 1 < points.size(); i++)
            res += hypot(points[i].first - points[i + 1].first, points[i].second - points[i + 1].second);
    }

    cout << "Scenario #" << test << ": " << (int)ceil(res / 100) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}