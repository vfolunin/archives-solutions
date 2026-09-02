#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;

        graph[a - 1].push_back({ b - 1, weight });
    }

    const int MOD = 1e9 + 7;
    vector<long long> dist(graph.size(), 1e18);
    vector<int> count(graph.size()), minEdges(graph.size()), maxEdges(graph.size());
    set<pair<long long, int>> q;

    dist[0] = 0;
    count[0] = 1;
    q.insert({ dist[0], 0 });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == graph.size() - 1)
            break;

        for (auto &[to, weight] : graph[v]) {
            if (dist[to] > dist[v] + weight) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + weight;
                count[to] = count[v];
                minEdges[to] = minEdges[v] + 1;
                maxEdges[to] = maxEdges[v] + 1;
                q.insert({ dist[to], to });
            } else if (dist[to] == dist[v] + weight) {
                count[to] = (count[to] + count[v]) % MOD;
                minEdges[to] = min(minEdges[to], minEdges[v] + 1);
                maxEdges[to] = max(maxEdges[to], maxEdges[v] + 1);
            }
        }
    }

    cout << dist.back() << " " << count.back() << " " << minEdges.back() << " " << maxEdges.back();
}