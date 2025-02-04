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
 
    int xl, yl, xr, yr, xc, yc, radius;
    cin >> xl >> yl >> xr >> yr >> xc >> yc >> radius;

    long long res = 0;

    for (int y = yl; y <= yr; y++) {
        int dy = abs(y - yc);
        if (dy > radius)
            continue;

        int dx = sqrt(1.0 * radius * radius - 1.0 * dy * dy);
        int l = max(xc - dx, xl);
        int r = min(xc + dx, xr);

        res += max(r - l + 1, 0);
    }

    cout << res;
}