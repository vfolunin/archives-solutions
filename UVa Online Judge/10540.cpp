#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double PI = acos(-1);

double symmetricLensArea(double r, double d) {
    return PI * r * r -
        2 * r * r * atan(d / sqrt(4 * r * r - d * d)) -
        d / 2 * sqrt(4 * r * r - d * d);
}

bool solve(int test) {
    int r, n;
    cin >> r >> n;

    if (!r && !n)
        return 0;

    double x1 = r, y1 = 0;

    vector<double> totalArea;
    for (int i = 0; i < (n + 1) / 2; i++) {
        double angle = 2 * PI * i / n;
        double x2 = r * cos(angle), y2 = r * sin(angle);
        double d = hypot(x1 - x2, y1 - y2);
        totalArea.push_back(n * symmetricLensArea(r, d));
    }
    reverse(totalArea.begin(), totalArea.end());

    vector<double> visibleArea = totalArea;
    double visibleAreaSum = visibleArea[0];
    for (int i = 1; i < visibleArea.size(); i++) {
        visibleArea[i] -= totalArea[i - 1] + visibleAreaSum;
        visibleAreaSum += visibleArea[i];
    }

    cout << "Set " << test << ":\n";
    cout << totalArea.size() << "\n";
    cout.precision(4);
    for (int i = 0; i < totalArea.size(); i++)
        cout << fixed << totalArea[i] << " " << visibleArea[i] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}