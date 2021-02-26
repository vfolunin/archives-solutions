#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<pair<long long, long long>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    auto [cx, cy] = points[pointCount / 2];

    int resA = 0, resB = 0;
    for (auto &[x, y] : points) {
        resA += x < cx && y < cy || x > cx && y > cy;
        resB += x < cx && y > cy || x > cx && y < cy;
    }

    cout << resA << " " << resB << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}