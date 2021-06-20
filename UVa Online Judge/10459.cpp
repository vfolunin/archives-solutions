#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> bfs(vector<vector<int>> &graph, const vector<int> &start) {
    vector<int> dist(graph.size(), 1e9);
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
                q.push(to);
            }
        }
    }

    return dist;
}

bool solve() {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        int degree;
        cin >> degree;
        graph[v].resize(degree);
        for (int &to : graph[v]) {
            cin >> to;
            to--;
        }
    }

    vector<int> dist = bfs(graph, { 0 });
    int a = max_element(dist.begin(), dist.end()) - dist.begin();

    vector<int> distA = bfs(graph, { a });
    int b = max_element(distA.begin(), distA.end()) - distA.begin();
    int diameter = distA[b];

    vector<int> distB = bfs(graph, { b }), bestRoots;
    for (int v = 0; v < vertexCount; v++)
        if (distA[v] + distB[v] == diameter && abs(distA[v] - distB[v]) <= 1)
            bestRoots.push_back(v);

    vector<int> distR = bfs(graph, bestRoots), worstRoots;
    int maxDistR = *max_element(distR.begin(), distR.end());
    for (int v = 0; v < vertexCount; v++)
        if (distR[v] == maxDistR)
            worstRoots.push_back(v);

    cout << "Best Roots  : ";
    for (int i = 0; i < bestRoots.size(); i++)
        cout << bestRoots[i] + 1 << (i + 1 < bestRoots.size() ? " " : "\n");
    cout << "Worst Roots : ";
    for (int i = 0; i < worstRoots.size(); i++)
        cout << worstRoots[i] + 1 << (i + 1 < worstRoots.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}