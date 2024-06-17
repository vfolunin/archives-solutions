#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, weight;
};

bool can(vector<vector<long long>> &dist, int rechargeLimit, long long distLimit) {
    int vertexCount = dist.size();

    vector<vector<int>> rechargeCount(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        rechargeCount[v][v] = 0;

    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            if (dist[a][b] <= distLimit)
                rechargeCount[a][b] = min(rechargeCount[a][b], 1);

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                rechargeCount[a][b] = min(rechargeCount[a][b], rechargeCount[a][v] + rechargeCount[v][b]);

    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            if (rechargeCount[a][b] > rechargeLimit)
                return 0;
    return 1;
}

void solve() {
    int vertexCount, rechargeLimit, edgeCount;
    cin >> vertexCount >> rechargeLimit >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, weight] : edges)
        cin >> a >> b >> weight;

    vector<vector<long long>> dist(vertexCount, vector<long long>(vertexCount, 1e18));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (auto &[a, b, weight] : edges)
        dist[a][b] = dist[b][a] = min<long long>(dist[a][b], weight);

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    long long l = 0, r = 1;
    while (!can(dist, rechargeLimit, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(dist, rechargeLimit, m))
            r = m;
        else
            l = m;
    }
    
    cout << r << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}