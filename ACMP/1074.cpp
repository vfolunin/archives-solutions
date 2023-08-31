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

    double x1, y1, r1, v1, x2, y2, r2, v2;
    cin >> x1 >> y1 >> r1 >> v1 >> x2 >> y2 >> r2 >> v2;

    cout << fixed << (hypot(x1 - x2, y1 - y2) - r1 - r2) / (v1 + v2);
}