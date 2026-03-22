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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;
    vertexCount *= 2;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[2 * a].push_back(2 * b + 1);
        graph[2 * a + 1].push_back(2 * b);
        graph[2 * b].push_back(2 * a + 1);
        graph[2 * b + 1].push_back(2 * a);
    }

    int startCount;
    cin >> startCount;

    set<int> start;
    for (int i = 0; i < startCount; i++) {
        int v;
        cin >> v;
        start.insert(v - 1);
    }

    vector<vector<int>> dist;
    for (int v : start)
        dist.push_back(bfs(graph, 2 * v));

    double res = 1e9;

    for (int v = 0; v < vertexCount; v++) {
        double cur = 0;
        for (vector<int> &d : dist)
            cur = max<double>(cur, d[v]);
        res = min(res, cur);
    }

    for (int v = 0; v < vertexCount; v++) {
        for (int to : graph[v]) {
            double cur = 0;
            for (vector<int> &d : dist)
                cur = max(cur, min({ d[v], d[v ^ 1], d[to], d[to ^ 1] }) + 0.5);
            res = min(res, cur);
        }
    }

    cout << (res != 1e9 ? res : -1);
}