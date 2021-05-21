#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<long long> x(pointCount), y(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i];

    long long res = 0;
    for (int i = 0; i < pointCount; i++) {
        map<long long, long long> count;
        for (int j = 0; j < pointCount; j++) {
            long long dx = x[i] - x[j], dy = y[i] - y[j];
            count[dx * dx + dy * dy]++;
        }
        for (auto &[_, k] : count)
            res += k * (k - 1) / 2;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}