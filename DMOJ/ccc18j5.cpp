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

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < graph.size(); v++) {
        int degree;
        cin >> degree;

        graph[v].resize(degree);
        for (int &to : graph[v]) {
            cin >> to;
            to--;
        }
    }

    vector<int> dist = bfs(graph, 0);

    cout << (count(dist.begin(), dist.end(), 1e9) ? "N\n" : "Y\n");

    int minDist = 1e9;
    for (int v = 0; v < graph.size(); v++)
        if (graph[v].empty())
            minDist = min(minDist, dist[v]);

    cout << minDist + 1;
}