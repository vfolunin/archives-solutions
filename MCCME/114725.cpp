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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  
    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    int edgeCount = 0;

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;

            if (hasEdge) {
                graph[a].push_back(b);
                edgeCount++;
            }
        }
    }

    vector<int> visited(vertexCount);
    dfs(graph, 0, visited);

    if (edgeCount == (vertexCount - 1) * 2 && !count(visited.begin(), visited.end(), 0))
        cout << "YES";
    else
        cout << "NO";
}