#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<double, double> &a, pair<double, double> &b) {
    return a.second < b.second;
}

bool solve() {
    int length, maxDistance, pointCount;
    if (!(cin >> length >> maxDistance >> pointCount))
        return 0;

    vector<pair<double, double>> segments(pointCount);
    for (auto &[l, r] : segments) {
        double x, y;
        cin >> x >> y;

        double dx = sqrt(maxDistance * maxDistance - y * y);
        l = x - dx;
        r = x + dx;
    }

    sort(segments.begin(), segments.end(), compare);

    int res = 0;
    double last = -1e9;
    for (auto &[l, r] : segments) {
        if (last + 1e-9 < l) {
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