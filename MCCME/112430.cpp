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

    double minX = 1e9, maxX = -1e9, maxY = -1e9;
    for (int i = 0; i < pointCount; i++) {
        double x, y;
        cin >> x >> y;

        if (y) {
            maxY = max(maxY, abs(y));
        } else {
            minX = min(minX, x);
            maxX = max(maxX, x);
        }
    }

    cout << fixed << (maxX - minX) * maxY / 2;
}