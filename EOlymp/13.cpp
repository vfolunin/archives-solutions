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

    double xSize, ySize, zSize, x1, y1, x2, y2, z2;
    cin >> xSize >> ySize >> zSize >> x1 >> y1 >> x2 >> y2 >> z2;

    if (!x2)
        x2 = -z2;
    else if (x2 == xSize)
        x2 = xSize + z2;
    else if (!y2)
        y2 = -z2;
    else if (y2 == ySize)
        y2 = ySize + z2;

    cout.precision(2);
    cout << fixed << hypot(x1 - x2, y1 - y2);
}