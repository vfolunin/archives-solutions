#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<pair<long long, long long>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    long long res = 0;
    for (int i = 0; i < points.size(); i++) {
        auto [x1, y1] = points[i];
        auto [x2, y2] = points[(i + 1) % points.size()];
        res += gcd(x1 - x2, y1 - y2);
    }

    cout << res;
}