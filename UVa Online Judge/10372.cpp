#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double PI = acos(-1), G = 9.8, EPS = 1e-9;

bool can(vector<pair<double, double>> buildings, double distance, double angle) {
    double v = sqrt(distance * G / (2 * sin(angle) * cos(angle)));
    double vx = v * cos(angle), vy = v * sin(angle);
    double x = 0;

    for (auto &[w, h] : buildings) {
        double t = x / vx;
        double y = vy * t - G * t * t / 2;
        if (y < h - EPS)
            return 0;

        x += w;
        t = x / vx;
        y = vy * t - G * t * t / 2;
        if (y < h - EPS)
            return 0;
    }

    return 1;
}

bool solve() {
    int buildingCount;
    if (!(cin >> buildingCount))
        return 0;

    vector<pair<double, double>> buildings(buildingCount);
    double distance = 0;
    for (auto &[w, h] : buildings) {
        cin >> h >> w;
        distance += w;
    }

    double l = 0, r = PI / 2;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (can(buildings, distance, m))
            r = m;
        else
            l = m;
    }

    double angle = l / PI * 180;
    double v = sqrt(distance * G / (2 * sin(l) * cos(l)));

    cout.precision(2);
    cout << fixed << angle << " " << v << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}