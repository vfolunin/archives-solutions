#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int circleCount;
    cin >> circleCount;

    vector<int> x(circleCount), y(circleCount), r(circleCount);
    for (int i = 0; i < circleCount; i++)
        cin >> x[i] >> y[i] >> r[i];

    int res = 0;
    for (int mask = 1; mask < (1 << circleCount); mask++) {
        bool ok = 1;

        for (int i = 0; ok && i < circleCount; i++) {
            if (!(mask & (1 << i)))
                continue;

            for (int j = i + 1; ok && j < circleCount; j++) {
                if (!(mask & (1 << j)))
                    continue;

                int x2 = (x[i] - x[j]) * (x[i] - x[j]);
                int y2 = (y[i] - y[j]) * (y[i] - y[j]);
                int r2 = r[i] * r[i] + 2 * r[i] * r[j] + r[j] * r[j];
                ok &= x2 + y2 > r2;
            }
        }

        if (ok) {
            int cur = 0;
            for (int i = 0; ok && i < circleCount; i++)
                if (mask & (1 << i))
                    cur += r[i] * r[i];
            res = max(res, cur);
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}