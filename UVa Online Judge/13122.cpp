#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int pointCount, removedCount;
    if (!(cin >> pointCount >> removedCount))
        return 0;

    vector<int> x(pointCount), y(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i];

    vector<vector<double>> res(pointCount, vector<double>(pointCount, 1e9));
    res[0][0] = 0;

    for (int last = 1; last < pointCount; last++) {
        for (int removed = 0; removed < last; removed++) {
            for (int prev = last - 1; prev >= 0 && removed >= last - prev - 1; prev--) {
                res[last][removed] = min(res[last][removed],
                                         res[prev][removed - (last - prev - 1)] +
                                         hypot(x[prev] - x[last], y[prev] - y[last]));
            }
        }
    }

    cout.precision(3);
    cout << fixed << res[pointCount - 1][removedCount] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}