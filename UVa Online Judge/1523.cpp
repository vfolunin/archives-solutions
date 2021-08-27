#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<int> weights(8);
    for (int &w : weights)
        cin >> w;

    sort(weights.begin(), weights.end());
    if (!weights.back())
        return 0;

    double res = 1e9;
    do {
        static int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
        static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

        int sy = 0, sx = 0;
        for (int i = 0; i < 8; i++) {
            sy += weights[i] * dy[i];
            sx += weights[i] * dx[i];
        }

        res = min(res, hypot(sy, sx));
    } while (next_permutation(weights.begin(), weights.end()));

    cout.precision(3);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}