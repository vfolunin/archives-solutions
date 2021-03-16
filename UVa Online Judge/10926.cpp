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

    vector<int> visited(vertexCount), depCount(vertexCount, 1);
    for (int v = 0; v < vertexCount; v++) {
        fill(visited.begin(), visited.end(), 0);
        dfs(graph, v, visited);
        depCount[v] = count(visited.begin(), visited.end(), 1) - 1;
    }

    cout << max_element(depCount.begin(), depCount.end()) - depCount.begin() + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}