#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> bfs(vector<vector<int>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, start, finish;
    cin >> vertexCount >> edgeCount >> start >> finish;
    start--;
    finish--;

    vector<vector<int>> graph(vertexCount);
    set<pair<int, int>> edges;

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
        edges.insert({ a, b });
        edges.insert({ b, a });
    }

    vector<int> distStart = bfs(graph, start);
    vector<int> distFinish = bfs(graph, finish);

    int res = 0;
    for (int a = 0; a < vertexCount; a++)
        for (int b = a + 1; b < vertexCount; b++)
            res += !edges.count({ a, b }) &&
            distStart[a] + 1 + distFinish[b] >= distStart[finish] &&
            distStart[b] + 1 + distFinish[a] >= distStart[finish];

    cout << res;
}