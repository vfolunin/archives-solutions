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

    int segmentCount, ringCount;
    double radius;
    cin >> segmentCount >> ringCount >> radius;

    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    double unitAngle = acos(-1) / segmentCount;
    double unitRadius = radius / ringCount;

    double dist1 = unitRadius * (b1 + b2);
    double dist2 = unitRadius * abs(b1 - b2) + unitRadius * min(b1, b2) * unitAngle * abs(a1 - a2);

    cout << fixed << min(dist1, dist2);
}