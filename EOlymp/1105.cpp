#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<vector<int>> &dist, int mask, int last, vector<vector<int>> &memo) {
    int &res = memo[mask][last];
    if (res != -1)
        return res;

    if (mask == 1)
        return res = 0;

    res = 1e9;
    for (int pred = ((mask - 1) & (mask - 2)) ? 1 : 0; pred < dist.size(); pred++)
        if (pred != last && (mask & (1 << pred)))
            res = min(res, rec(dist, mask ^ (1 << last), pred, memo) + dist[pred][last]);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;
    vertexCount++;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> dist[a][b];

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    vector<vector<int>> memo(1 << vertexCount, vector<int>(vertexCount, -1));
    int res = 1e9;
    for (int last = 1; last < vertexCount; last++)
        res = min(res, rec(dist, (1 << vertexCount) - 1, last, memo) + dist[last][0]);

    cout << res;
}