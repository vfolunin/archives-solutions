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
    for (int v = 0; v < vertexCount; v++) {
        int degree;
        cin >> degree;

        graph[v].resize(degree);
        for (int &to : graph[v]) {
            cin >> to;
            to--;
        }
    }

    vector<int> visited(vertexCount);
    int ccCount = 0;

    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v]) {
            dfs(graph, v, visited);
            ccCount++;
        }
    }

    cout << ccCount;
}