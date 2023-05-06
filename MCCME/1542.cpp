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

    double radius, x0, y0;
    cin >> radius >> x0 >> y0;

    long long res = 0;
    for (long long y = y0 - radius - 1; y <= y0 + radius + 1; y++) {
        double dy = y - y0;
        if (radius * radius >= dy * dy) {
            double dx = sqrt(radius * radius - dy * dy);
            res += floor(x0 + dx) - ceil(x0 - dx) + 1;
        }
    }

    cout << res;
}