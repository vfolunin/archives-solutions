#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> bfs(vector<vector<int>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    vector<int> from(graph.size(), -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }

    vector<int> path;
    if (dist[finish] != 1e9) {
        for (int v = finish; v != -1; v = from[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
    }
    return path;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;
            if (hasEdge)
                graph[a].push_back(b);
        }
    }

    int start, finish;
    cin >> start >> finish;

    vector<int> path = bfs(graph, start - 1, finish - 1);

    if (path.empty()) {
        cout << -1;
    } else if (path.size() == 1) {
        cout << 0;
    } else {
        cout << path.size() - 1 << "\n";
        for (int v : path)
            cout << v + 1 << " ";
    }
}