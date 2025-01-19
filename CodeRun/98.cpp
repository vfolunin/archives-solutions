#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<int> x(pointCount), y(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i];

    int res = 0;
    for (int a = 0; a < pointCount; a++) {
        unordered_map<long long, int> dist2Count;
        unordered_set<long long> vectors;

        for (int b = 0; b < pointCount; b++) {
            long long dx = x[a] - x[b];
            long long dy = y[a] - y[b];
            long long dist2 = dx * dx + dy * dy;

            res += dist2Count[dist2];
            res -= vectors.count(-dx * 1e9 - dy);

            dist2Count[dist2]++;
            vectors.insert(dx * 1e9 + dy);
        }
    }

    cout << res;
}