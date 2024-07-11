#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int dist(int sx, int sy, vector<int> &x, vector<int> &y, int mask, int last, vector<vector<int>> &memo) {
    if (memo[mask][last] != -1)
        return memo[mask][last];

    if (!(mask & (mask - 1)))
        return memo[mask][last] = dist(sx, sy, x[last], y[last]);

    int res = 1e9;
    for (int pred = 0; pred < x.size(); pred++) {
        if (pred == last || !(mask & (1 << pred)))
            continue;
        res = min(res, dist(sx, sy, x, y, mask ^ (1 << last), pred, memo) + dist(x[pred], y[pred], x[last], y[last]));
    }
    return memo[mask][last] = res;
}

void solve() {
    int w, h, sx, sy, n;
    cin >> w >> h >> sx >> sy >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    vector<vector<int>> memo(1 << n, vector<int>(n, -1));
    int res = 1e9;
    for (int last = 0; last < n; last++)
        res = min(res, dist(sx, sy, x, y, (1 << n) - 1, last, memo) + dist(x[last], y[last], sx, sy));

    cout << "The shortest path has length " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}