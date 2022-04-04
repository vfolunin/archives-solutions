#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long prim(vector<vector<pair<int, int>>> &graph, vector<int> &startVertices) {
    vector<int> dist(graph.size(), 1e9);
    vector<int> visited(graph.size());
    set<pair<int, int>> q;

    for (int v : startVertices) {
        dist[v] = 0;
        q.insert({ dist[v], v });
    }

    long long mstWeight = 0;

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        visited[v] = true;
        mstWeight += dist[v];

        for (auto &[to, w] : graph[v]) {
            if (!visited[to] && dist[to] > w) {
                q.erase({ dist[to], to });
                dist[to] = w;
                q.insert({ dist[to], to });
            }
        }
    }

    return mstWeight;
}

void solve() {
    int vertexCount, edgeCount, programSize, startVertexCount;
    cin >> vertexCount >> edgeCount >> programSize >> startVertexCount;

    vector<int> startVertices(startVertexCount);
    for (int &v : startVertices) {
        cin >> v;
        v--;
    }

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].push_back({ b, w + programSize });
        graph[b].push_back({ a, w + programSize });
    }

    long long mstWeight = prim(graph, startVertices);

    cout << mstWeight << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}