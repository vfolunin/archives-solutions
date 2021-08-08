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

bool solve(int test) {
    int segmentCount, radius;
    cin >> segmentCount >> radius;

    if (!segmentCount)
        return 0;

    vector<pair<double, double>> segments(segmentCount);
    bool ok = 1;
    for (auto &[l, r] : segments) {
        double x, y;
        cin >> x >> y;

        if (y <= radius) {
            double dx = sqrt(radius * radius - y * y);
            l = x - dx;
            r = x + dx;
        } else {
            ok = 0;
        }
    }

    cout << "Case " << test << ": ";

    if (!ok) {
        cout << "-1\n";
        return 1;
    }

    sort(segments.begin(), segments.end(), compare);

    int count = 0;
    double last = -1e9;
    for (auto &[l, r] : segments) {
        if (last + 1e-9 < l) {
            count++;
            last = r;
        }
    }

    cout << count << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}