#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }
};

bool solve() {
    double distanceLimit;
    int hiveCount;
    cin >> distanceLimit >> hiveCount;

    if (!distanceLimit && !hiveCount)
        return 0;

    vector<Point> hives(hiveCount);
    for (auto &[x, y] : hives)
        cin >> x >> y;

    int sweetCount = 0;
    for (int i = 0; i < hiveCount; i++) {
        bool isSweet = 1;
        for (int j = 0; isSweet && j < hiveCount; j++)
            isSweet &= i == j || hives[i].distanceTo(hives[j]) > distanceLimit;
        sweetCount += isSweet;
    }

    cout << hiveCount - sweetCount << " sour, " << sweetCount << " sweet\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}