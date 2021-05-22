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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    vector<int> visited(vertexCount), ccRep;
    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v]) {
            ccRep.push_back(v);
            dfs(graph, v, visited);
        }
    }

    cout << ccRep.size() - 1 << "\n";
    for (int i = 1; i < ccRep.size(); i++)
        cout << ccRep[0] + 1 << " " << ccRep[i] + 1 << "\n";
}