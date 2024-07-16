#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    int res = 1;
    for (int to : graph[v])
        if (!visited[to])
            res += dfs(graph, to, visited);
    return res;
}

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (vertexCount == -1)
        return 0;

    vector<double> x(vertexCount), y(vertexCount), r(vertexCount);
    for (int i = 0; i < vertexCount; i++)
        cin >> x[i] >> y[i] >> r[i];

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        for (int j = i + 1; j < vertexCount; j++) {
            double dist = hypot(x[i] - x[j], y[i] - y[j]);
            if (fabs(r[i] - r[j]) < dist && dist < r[i] + r[j]) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<int> visited(vertexCount);
    int res = 0;
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            res = max(res, dfs(graph, v, visited));

    cout << "The largest component contains " << res << " ring" << (res == 1 ? "" : "s") << ".\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}