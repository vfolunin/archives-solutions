#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int mask, int last, vector<int> &point, vector<vector<int>> &dist, vector<vector<int>> &memo) {
    int &res = memo[mask][last];
    if (res != -1)
        return res;

    if (!(mask & (mask - 1)))
        return res = dist[0][point[last]];

    res = 1e9;
    for (int pred = 0; pred < point.size(); pred++) {
        if (pred == last || !(mask & (1 << pred)))
            continue;
        res = min(res, rec(mask ^ (1 << last), pred, point, dist, memo) + dist[point[pred]][point[last]]);
    }
    return res;
}

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;
    vertexCount++;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        double w;
        cin >> a >> b >> w;
        dist[a][b] = dist[b][a] = min<int>(dist[a][b], round(w * 100));
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int pointCount;
    cin >> pointCount;

    vector<int> point(pointCount), bonus(pointCount);
    for (int i = 0; i < pointCount; i++) {
        double b;
        cin >> point[i] >> b;
        bonus[i] = round(b * 100);
    }

    vector<vector<int>> memo(1 << pointCount, vector<int>(pointCount, -1));
    int res = 0;
    for (int mask = 0; mask < (1 << pointCount); mask++) {
        int curDist = 1e9, curBonus = 0;
        for (int last = 0; last < pointCount; last++) {
            if (mask & (1 << last)) {
                curDist = min(curDist, rec(mask, last, point, dist, memo) + dist[0][point[last]]);
                curBonus += bonus[last];
            }
        }
        res = max(res, curBonus - curDist);
    }

    if (res > 0) {
        cout.precision(2);
        cout << "Daniel can save $" << fixed << res / 100.0 << "\n";
    } else {
        cout << "Don't leave the house\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}