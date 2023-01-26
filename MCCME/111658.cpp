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

    double minPX = 1e9, maxPX = -1e9, maxPY = 0;
    double minNX = 1e9, maxNX = -1e9, maxNY = 0;
    for (int i = 0; i < pointCount; i++) {
        double x, y;
        cin >> x >> y;

        if (y) {
            if (x > 0)
                maxPY = max(maxPY, abs(y));
            else if (x < 0)
                maxNY = max(maxNY, abs(y));
        } else {
            if (x > 0) {
                minPX = min(minPX, x);
                maxPX = max(maxPX, x);
            } else if (x < 0) {
                minNX = min(minNX, x);
                maxNX = max(maxNX, x);
            }
        }
    }

    cout << fixed << max({ 0.0, (maxPX - minPX) * maxPY, (maxNX - minNX) * maxNY }) / 2;
}