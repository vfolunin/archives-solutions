#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targetX, targetY, shieldCount;
    cin >> targetX >> targetY >> shieldCount;

    vector<pair<double, double>> shields(shieldCount);
    int freeSize = targetY;

    for (auto &[size, factor] : shields) {
        int from, to;
        cin >> from >> to >> factor;
        size = to - from;
        freeSize -= size;
    }

    shields.push_back({ freeSize, 1 });

    double l = -1e9, r = 1e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2, x = 0;
        for (auto &[size, factor] : shields)
            x += size * factor * m;

        if (x < targetX)
            l = m;
        else
            r = m;
    }

    cout << fixed << l;
}