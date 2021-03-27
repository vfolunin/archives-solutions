#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    double distTo(const Point &that) {
        return hypot(x - that.x, y - that.y);
    }
};

double rec(vector<Point> &p, int a, int b, vector<vector<double>> &memo) {
    if (memo[a][b])
        return memo[a][b];

    if (a == p.size() - 1)
        return memo[a][b] = p[a].distTo(p[b]);

    memo[a][b] = p[a].distTo(p[a + 1]) + rec(p, a + 1, b, memo);

    double backPath = p[b].distTo(p[a + 1]);
    for (int i = a + 2; i < p.size(); i++) {
        memo[a][b] = min(memo[a][b], p[a].distTo(p[i]) + rec(p, i, i - 1, memo) + backPath);
        backPath += p[i - 1].distTo(p[i]);
    }

    return memo[a][b];
}

bool solve() {
    int pointCount;
    if (!(cin >> pointCount))
        return 0;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    vector<vector<double>> memo(pointCount, vector<double>(pointCount));
    double res = rec(points, 1, 0, memo);
    res += points[0].distTo(points[1]);

    cout.precision(2);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}