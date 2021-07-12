#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<pair<int, int>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    int l = -1e9, r = 1e9, d = -1e9, u = 1e9;
    for (int i = 0; i < pointCount; i++) {
        auto &[ax, ay] = points[i];
        auto &[bx, by] = points[(i + 1) % pointCount];

        if (ax == bx && ay < by)
            l = max(l, ax);
        if (ax == bx && ay > by)
            r = min(r, ax);
        if (ay == by && ax < bx)
            u = min(u, ay);
        if (ay == by && ax > bx)
            d = max(d, ay);
    }

    cout << "Floor #" << test << "\nSurveillance is ";
    if (l <= r && d <= u)
        cout << "possible";
    else
        cout << "impossible";
    cout << ".\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}