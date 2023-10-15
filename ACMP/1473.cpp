#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color) {
    visited[v] = color;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, color);
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
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int capitalCount;
    cin >> capitalCount;

    vector<int> capitals(capitalCount), visited(vertexCount);
    for (int i = 0; i < capitalCount; i++) {
        cin >> capitals[i];
        capitals[i]--;
        visited[capitals[i]] = i + 1;
    }

    for (int i = 0; i < capitals.size(); i++) {
        dfs(graph, capitals[i], visited, i + 1);

        cout << count(visited.begin(), visited.end(), i + 1) << "\n";
        for (int v = 0; v < graph.size(); v++)
            if (visited[v] == i + 1)
                cout << v + 1 << " ";
        cout << "\n";
    }
}