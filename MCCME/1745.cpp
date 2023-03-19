#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long dijkstra(vector<vector<vector<int>>> &graph, int start, int finish, long long startDist) {
    vector<long long> dist(graph.size(), 1e18);
    dist[start] = startDist;
    set<pair<long long, int>> q = { { dist[start], start } };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v == finish)
            return dist[finish];

        for (auto &edge : graph[v]) {
            int to = edge[0], t1 = edge[1], t2 = edge[2];
            long long distTo = (dist[v] + t1 - 1) / t1 * t1 + t2;

            if (dist[to] > distTo) {
                q.erase({ dist[to], to });
                dist[to] = distTo;
                q.insert({ dist[to], to });
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<vector<int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, ta, tb;
        cin >> a >> b >> ta >> tb;
        a--;
        b--;
        graph[a].push_back({ b, ta, tb });
    }

    int milestoneCount;
    cin >> milestoneCount;

    vector<int> milestones(milestoneCount);
    for (int &v : milestones) {
        cin >> v;
        v--;
    }

    long long startDist = 0;
    for (int i = 0; i + 1 < milestoneCount; i++) {
        long long finishDist = dijkstra(graph, milestones[i], milestones[i + 1], startDist);
        if (finishDist == -1) {
            cout << -1;
            return 0;
        }
        startDist = finishDist;
    }

    cout << startDist;
}