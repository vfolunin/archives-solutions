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

    double x, y, r;
    cin >> x >> y >> r;

    if (r < abs(y)) {
        cout << 0;
    } else if (r == abs(y)) {
        cout << "1\n" << fixed << x;
    } else {
        double d = sqrt(r * r - y * y);
        cout << "2\n" << fixed << x - d << "\n" << x + d;
    }
}