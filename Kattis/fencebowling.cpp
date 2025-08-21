#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(double bounceCount, double w, double h, double angle) {
    double dist = 0;
    for (int i = 0; i < bounceCount; i++) {
        dist += tan(angle) * w;
        angle = atan(2 * tan(angle));
        dist += tan(angle) * w;
    }
    return dist > h;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double bounceCount, w, h;
    cin >> bounceCount >> w >> h;

    w /= 2;

    double l = 0, r = acos(0);
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (can(bounceCount, w, h, m))
            r = m;
        else
            l = m;
    }

    cout << fixed << l / acos(-1) * 180;
}