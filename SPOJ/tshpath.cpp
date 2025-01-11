#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    set<pair<int, int>> q;

    dist[start] = 0;
    q.insert({ dist[start], start });

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

    return dist[finish];
}

int getId(map<string, int> &id, string &name) {
    if (!id.count(name))
        id[name] = id.size();
    return id[name];
}

void solve() {
    int vertexCount;
    cin >> vertexCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    map<string, int> id;

    for (int v = 0; v < vertexCount; v++) {
        string name;
        int degree;
        cin >> name >> degree;

        getId(id, name);
        for (int i = 0; i < degree; i++) {
            int to, w;
            cin >> to >> w;
            graph[v].push_back({ to - 1, w });
        }
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string a, b;
        cin >> a >> b;

        cout << dijkstra(graph, getId(id, a), getId(id, b)) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}