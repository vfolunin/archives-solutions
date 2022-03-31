#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Circle {
    int x, y, r = 0;

    double distanceTo(const Circle &that) const {
        return max(0.0, hypot(x - that.x, y - that.y) - r - that.r);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Circle center;
    int pointCount;
    cin >> center.x >> center.y >> pointCount;

    vector<int> distances(pointCount);
    for (int &distance : distances) {
        Circle circle;
        cin >> circle.x >> circle.y >> circle.r;
        distance = center.distanceTo(circle);
    }
    sort(distances.begin(), distances.end());

    cout << distances[2];
}