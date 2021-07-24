#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double PI = acos(-1);

double getVolumeHorizontal(double h, double w, double r) {
    if (2 * r + 2 * PI * r <= w)
        return PI * r * r * h;
    return 0;
}

double getVolumeVertical(double h, double w, double r) {
    if (2 * PI * r <= h)
        return PI * r * r * (w - 2 * r);
    return 0;
}

template<typename F>
double findVolume(double h, double w, F getVolume) {
    double l = 0, r = h / 2;
    for (int i = 0; i < 100; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double v1 = getVolume(h, w, m1);
        double v2 = getVolume(h, w, m2);
        if (v1 < v2)
            l = m1;
        else
            r = m2;
    }
    return getVolume(h, w, l);
}

bool solve() {
    double h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    double res = 0;
    res = max(res, findVolume(h, w, getVolumeHorizontal));
    res = max(res, findVolume(h, w, getVolumeVertical));

    cout.precision(3);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}