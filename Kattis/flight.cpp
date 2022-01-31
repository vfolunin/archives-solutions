#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph;

    void dfs(int v, int a, int b, vector<int> &visited) {
        visited[v] = 1;
        for (int to : graph[v]) {
            if (v == a && to == b || v == b && to == a)
                continue;
            if (!visited[to])
                dfs(to, a, b, visited);
        }
    }

    vector<int> bfs(int v, int a, int b) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;

        dist[v] = 0;
        q.push(v);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : graph[v]) {
                if (v == a && to == b || v == b && to == a)
                    continue;
                if (dist[to] == 1e9) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return dist;
    }

    Graph(int vertexCount) : graph(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    pair<int, int> getDiameter(int v, int a, int b) {
        vector<int> dist = bfs(v, a, b);
        int va = -1;
        for (int v = 0; v < graph.size(); v++)
            if (dist[v] != 1e9 && (va == -1 || dist[v] > dist[va]))
                va = v;

        vector<int> distA = bfs(va, a, b);
        int vb = -1;
        for (int v = 0; v < graph.size(); v++)
            if (dist[v] != 1e9 && (vb == -1 || distA[v] > distA[vb]))
                vb = v;
        int diameter = distA[vb];

        vector<int> distB = bfs(vb, a, b);
        int center = -1;
        for (int v = 0; v < graph.size(); v++)
            if (distA[v] + distB[v] == diameter && abs(distA[v] - distB[v]) <= 1)
                center = v;

        return { diameter, center };
    }

    void check(int a, int b, vector<int> &res) {
        vector<int> visited(graph.size());
        dfs(0, a, b, visited);

        int va = 0, vb = 0;
        while (visited[va] == visited[vb])
            vb++;

        auto [da, ca] = getDiameter(va, a, b);
        auto [db, cb] = getDiameter(vb, a, b);
        int d = max(max(da, db), (da + 1) / 2 + 1 + (db + 1) / 2);
        if (res[0] > d)
            res = { d, a, b, ca, cb };
    }
};

void solve() {
    int vertexCount;
    cin >> vertexCount;

    Graph graph(vertexCount);
    vector<pair<int, int>> edges(vertexCount - 1);

    for (auto &[a, b] : edges) {
        cin >> a >> b;
        a--;
        b--;
        graph.addEdge(a, b);
    }

    vector<int> res(5);
    res[0] = 1e9;

    for (auto &[a, b] : edges)
        graph.check(a, b, res);

    cout << res[0] << "\n";
    cout << res[1] + 1 << " " << res[2] + 1 << "\n";
    cout << res[3] + 1 << " " << res[4] + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}