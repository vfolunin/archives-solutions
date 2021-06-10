#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(double shift, vector<pair<double, double>> &segments, double totalTime) {
    double time = 0;
    for (auto &[distance, speed] : segments)
        time += distance / (speed - shift);
    return time <= totalTime;
}

bool solve() {
    int segmentCount, totalTime;
    if (!(cin >> segmentCount >> totalTime))
        return 0;

    vector<pair<double, double>> segments(segmentCount);
    double minSpeed = 1e9;
    for (auto &[distance, speed] : segments) {
        cin >> distance >> speed;
        minSpeed = min(minSpeed, speed);
    }

    double l = -1e9, r = minSpeed;
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        if (can(m, segments, totalTime))
            l = m;
        else
            r = m;
    }

    cout.precision(9);
    cout << fixed << -l << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}