#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double outerRadius;
    int circleCount;
    if (!(cin >> outerRadius >> circleCount))
        return 0;

    cout.precision(10);
    if (circleCount == 1) {
        cout << fixed << outerRadius << " " << 0.0 << " " << 0.0 << "\n";
        return 1;
    }

    const double PI = acos(-1);
    double halfSectorAngle = PI / 2 * (circleCount - 2) / circleCount;
    double innerRadius = (outerRadius * cos(halfSectorAngle)) / (1 + cos(halfSectorAngle));
    double polygonArea = circleCount * innerRadius * innerRadius / tan(PI / circleCount);
    double sectorArea = halfSectorAngle * innerRadius * innerRadius;
    double innerArea = polygonArea - circleCount * sectorArea;
    double outerArea = PI * (outerRadius * outerRadius - circleCount * innerRadius * innerRadius) - innerArea;
    
    cout << fixed << innerRadius << " " << innerArea << " " << outerArea << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}