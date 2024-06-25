#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<long long> &salary) {
    visited[v] = 1;
    salary[v] = graph[v].empty();
    for (int to : graph[v]) {
        if (!visited[to])
            dfs(graph, to, visited, salary);
        salary[v] += salary[to];
    }
}

bool solve() {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    vector<vector<int>> graph(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            char hasEdge;
            cin >> hasEdge;

            if (hasEdge == 'Y')
                graph[a].push_back(b);
        }
    }

    vector<int> visited(vertexCount);
    vector<long long> salary(vertexCount);
    long long res = 0;
    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v])
            dfs(graph, v, visited, salary);
        res += salary[v];
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}