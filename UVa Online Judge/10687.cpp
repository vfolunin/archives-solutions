#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    vector<int> x(vertexCount), y(vertexCount);
    for (int i = 0; i < vertexCount; i++)
        cin >> x[i] >> y[i];

    vector<vector<int>> graph(vertexCount);

    for (int v = 0; v < vertexCount; v++) {
        for (int i = 0; i < 2; i++) {
            int bestTo = -1, bestDist;
            for (int to = 0; to < vertexCount; to++) {
                if (v == to ||  find(graph[v].begin(), graph[v].end(), to) != graph[v].end())
                    continue;
                int dist = (x[v] - x[to]) * (x[v] - x[to]) + (y[v] - y[to]) * (y[v] - y[to]);
                if (bestTo == -1 || dist < bestDist ||
                    dist == bestDist && x[to] < x[bestTo] ||
                    dist == bestDist && x[to] == x[bestTo] && y[to] == y[bestTo]) {
                    bestTo = to;
                    bestDist = dist;
                }
            }
            if (bestTo != -1)
                graph[v].push_back(bestTo);
        }
    }

    vector<int> visited(vertexCount);
    dfs(graph, 0, visited);

    if (count(visited.begin(), visited.end(), 1) == vertexCount)
        cout << "All stations are reachable.\n";
    else
        cout << "There are stations that are unreachable.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}