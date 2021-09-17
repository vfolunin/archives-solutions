#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int INF = 1e8;

int dijkstra(vector<vector<int>> &dist) {
    int vertexCount = dist.size();

    vector<vector<int>> cost(vertexCount, vector<int>(vertexCount, INF));
    set<pair<int, pair<int, int>>> q;

    cost[0][0] = 1;
    q.insert({ 1, { 0, 0 } });

    while (!q.empty()) {
        auto [a, b] = q.begin()->second;
        q.erase(q.begin());

        if (a != b && cost[b][a] > cost[a][b] + dist[b][a] - 1) {
            cost[b][a] = cost[a][b] + dist[b][a] - 1;
            q.insert({ cost[b][a], { b, a } });
        }

        for (int v = 0; v < vertexCount; v++) {
            if (dist[v][a] == 1 && cost[v][b] > cost[a][b] + (v != b)) {
                cost[v][b] = cost[a][b] + (v != b);
                q.insert({ cost[v][b], { v, b } });
            }
        }

        for (int v = 0; v < vertexCount; v++) {
            if (dist[b][v] == 1 && cost[a][v] > cost[a][b] + (a != v)) {
                cost[a][v] = cost[a][b] + (a != v);
                q.insert({ cost[a][v], { a, v } });
            }
        }
    }

    return cost[1][1];
}

bool solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, INF));

    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        dist[a - 1][b - 1] = 1;
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);


    cout << "Network " << test << "\n";
    if (dist[0][1] == INF || dist[1][0] == INF)
        cout << "Impossible\n";
    else
        cout << "Minimum number of nodes = " << dijkstra(dist) << "\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}