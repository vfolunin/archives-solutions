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

    double xSum = 0, ySum = 0;
    for (int i = 0; i < pointCount; i++) {
        double x, y;
        cin >> x >> y;
        xSum += x;
        ySum += y;
    }

    cout << fixed << xSum / pointCount << " " << ySum / pointCount;
}