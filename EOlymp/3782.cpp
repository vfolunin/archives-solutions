#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int radius, pointCount;
    cin >> radius >> pointCount;

    vector<int> x(pointCount), y(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i];

    double circleSize = 2 * acos(-1) * radius;
    double polygonSize = 0;
    for (int i = 0; i < pointCount; i++)
        polygonSize += hypot(x[i] - x[(i + 1) % pointCount], y[i] - y[(i + 1) % pointCount]);

    if (polygonSize >= circleSize)
        cout << fixed << (polygonSize - circleSize) / polygonSize << "\n";
    else
        cout << "Not possible\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}