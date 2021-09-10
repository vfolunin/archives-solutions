#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    double angle() const {
        double a = atan2(y, x);
        if (a < -EPS)
            a += 2 * acos(-1.0);
        return a;
    }
};

bool compare(pair<double, double> &a, pair<double, double> &b) {
    return a.second < b.second;
}

bool solve() {
    int segmentCount;
    cin >> segmentCount;

    if (!segmentCount)
        return 0;

    vector<pair<double, double>> segments(segmentCount);
    for (auto &[l, r] : segments) {
        Point a, b;
        cin >> a.x >> a.y >> b.x >> b.y;

        l = a.angle();
        r = b.angle();
        if (l > r)
            swap(l, r);
    }

    sort(segments.begin(), segments.end(), compare);

    int res = 0;
    double last = -1e9;
    for (auto &[l, r] : segments) {
        if (last + EPS < l) {
            res++;
            last = r;
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}