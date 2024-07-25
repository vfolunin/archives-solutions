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

    double x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    if (x1 > x2)
        swap(x1, x2);
    if (x3 > x4)
        swap(x3, x4);
    double w = max(min(x2, x4) - max(x1, x3), 0.0);

    if (y1 > y2)
        swap(y1, y2);
    if (y3 > y4)
        swap(y3, y4);
    double h = max(min(y2, y4) - max(y1, y3), 0.0);

    cout.precision(3);
    cout << fixed << w * h;
}