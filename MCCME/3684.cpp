#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getDist(vector<pair<double, double>> &a, double t) {
    double minX = 1e100, maxX = -1e100;
    for (auto &[x, v] : a) {
        double curX = x + v * t;
        minX = min(minX, curX);
        maxX = max(maxX, curX);
    }
    return maxX - minX;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int size;
    cin >> size;

    vector<pair<double, double>> a(size);
    for (auto &[x, v] : a)
        cin >> x >> v;

    double l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (getDist(a, m1) < getDist(a, m2))
            r = m2;
        else
            l = m1;
    }

    cout << fixed << l << " " << getDist(a, l);
}