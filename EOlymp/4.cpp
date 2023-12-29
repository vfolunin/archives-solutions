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

    double x1, y1, radius1, x2, y2, radius2;
    cin >> x1 >> y1 >> radius1 >> x2 >> y2 >> radius2;

    if (radius1 > radius2) {
        swap(x1, x2);
        swap(y1, y2);
        swap(radius1, radius2);
    }

    const double EPS = 1e-9;

    if (abs(x1 - x2) < EPS && abs(y1 - y2) < EPS && abs(radius1 - radius2) < EPS) {
        cout << -1;
    } else if (radius1 + radius2 + EPS < hypot(x1 - x2, y1 - y2) || 
               radius1 + hypot(x1 - x2, y1 - y2) + EPS < radius2) {
        cout << 0;
    } else if (abs(hypot(x1 - x2, y1 - y2) - radius1 - radius2) < EPS ||
               abs(hypot(x1 - x2, y1 - y2) + radius1 - radius2) < EPS) {
        cout << 1;
    } else {
        cout << 2;
    }
}