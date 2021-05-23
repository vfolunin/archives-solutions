#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int pointCount, queryCount;
    cin >> pointCount >> queryCount;

    if (!pointCount && !queryCount)
        return 0;

    vector<int> x(pointCount), y(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i];

    vector<int> dist;
    for (int i = 0; i < pointCount; i++)
        for (int j = i + 1; j < pointCount; j++)
            dist.push_back((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    sort(dist.begin(), dist.end());

    for (int i = 0; i < queryCount; i++) {
        int r;
        cin >> r;
        
        double res = upper_bound(dist.begin(), dist.end(), r * r) - dist.begin();
        res = res * 2 / pointCount + 1;

        cout.precision(2);
        cout << fixed << res << "\n";
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}