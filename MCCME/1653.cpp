#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<vector<int>, vector<int>> bfs(vector<vector<int>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9), parent(graph.size(), -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                parent[to] = v;
                q.push(to);
            }
        }
    }

    return { dist, parent };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> dist0 = bfs(graph, 0).first;
    int a = max_element(dist0.begin(), dist0.end()) - dist0.begin();
    vector<int> distA = bfs(graph, a).first;
    int diameter = *max_element(distA.begin(), distA.end());

    cout << diameter + 1;
}