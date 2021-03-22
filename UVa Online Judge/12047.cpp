#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>> &graph, int startVertex) {
    vector<long long> dist(graph.size(), 1e18);
    dist[startVertex] = 0;
    set<pair<int, int>> q = { { dist[startVertex], startVertex } };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist;
}

void solve() {
    int vertexCount, edgeCount, start, finish, limit;
    cin >> vertexCount >> edgeCount >> start >> finish >> limit;
    start--;
    finish--;

    vector<vector<pair<int, int>>> graph(vertexCount), graphR(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;

        graph[a].push_back({ b, w });
        graphR[b].push_back({ a, w });
    }

    vector<long long> distS = dijkstra(graph, start);
    vector<long long> distF = dijkstra(graphR, finish);

    int res = -1;
    for (int v = 0; v < vertexCount; v++)
        for (auto &[to, w] : graph[v])
            if (distS[v] + w + distF[to] <= limit)
                res = max(res, w);
    
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