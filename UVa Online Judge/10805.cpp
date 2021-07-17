#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<vector<int>, vector<int>> bfs(vector<vector<int>> &graph, const vector<int> &start) {
    vector<int> dist(graph.size(), 1e9), parent(graph.size(), -1);
    queue<int> q;

    for (int v : start) {
        dist[v] = 0;
        q.push(v);
    }

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

int getDiameter(vector<vector<int>> &graph) {
    vector<int> dist0 = bfs(graph, { 0 }).first;
    int a = max_element(dist0.begin(), dist0.end()) - dist0.begin();
    vector<int> distA = bfs(graph, { a }).first;
    return *max_element(distA.begin(), distA.end());
}

int getDiameter(vector<vector<int>> &graph, const vector<int> &start) {
    auto [_, parent] = bfs(graph, start);

    vector<vector<int>> tree(graph.size());
    for (int v = 0; v < graph.size(); v++) {
        if (parent[v] != -1) {
            tree[parent[v]].push_back(v);
            tree[v].push_back(parent[v]);
        }
    }

    if (start.size() == 2) {
        tree[start[0]].push_back(start[1]);
        tree[start[1]].push_back(start[0]);
    }

    return getDiameter(tree);
}

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int res = 1e9;
    for (int v = 0; v < vertexCount; v++) {
        res = min(res, getDiameter(graph, { v }));
        for (int to : graph[v])
            res = min(res, getDiameter(graph, { v, to }));
    }

    cout << "Case #" << test << ":\n" << res << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}