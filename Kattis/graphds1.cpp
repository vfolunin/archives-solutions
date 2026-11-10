#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfsConnected(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfsConnected(graph, to, visited);
}

void dfsBipartite(vector<vector<int>> &graph, int v, vector<int> &visited, int color, bool &isBipartite) {
    visited[v] = color;
    for (int to : graph[v]) {
        if (!visited[to])
            dfsBipartite(graph, to, visited, 3 - color, isBipartite);
        else if (visited[to] == color)
            isBipartite = 0;
    }
}

void dfsCycle(vector<vector<int>> &directedGraph, int v, vector<int> &visited, bool &hasCycle) {
    visited[v] = 1;
    for (int to : directedGraph[v]) {
        if (!visited[to])
            dfsCycle(directedGraph, to, visited, hasCycle);
        else if (visited[to] == 1)
            hasCycle = 1;
    }
    visited[v] = 2;
}

bool checkTree(vector<vector<int>> &graph, vector<int> &inDegree, int edgeCount, bool isDirected) {
    if (edgeCount != graph.size() - 1)
        return 0;

    int root = isDirected ? -1 : 0;
    if (isDirected) {
        for (int v = 0; v < graph.size(); v++) {
            if (!inDegree[v]) {
                if (root == -1)
                    root = v;
                else
                    return 0;
            }
        }
        if (root == -1)
            return 0;
    }

    vector<int> visited(graph.size());
    dfsConnected(graph, root, visited);
    return !count(visited.begin(), visited.end(), 0);
}

bool checkComplete(int vertexCount, int edgeCount, bool isDirected) {
    long long targetEdgeCount = vertexCount * (vertexCount - 1LL);
    if (!isDirected)
        targetEdgeCount /= 2;
    return edgeCount == targetEdgeCount;
}

bool checkBipartite(vector<vector<int>> &graph, vector<int> &inDegree, bool isDirected) {
    if (isDirected) {
        for (int v = 0; v < graph.size(); v++)
            if (inDegree[v] && !graph[v].empty())
                return 0;
        return 1;
    }

    vector<int> visited(graph.size());
    bool isBipartite = 1;
    for (int v = 0; v < graph.size(); v++)
        if (!visited[v])
            dfsBipartite(graph, v, visited, 1, isBipartite);
    return isBipartite;
}

bool checkDag(vector<vector<int>> &graph) {
    vector<int> visited(graph.size());
    bool hasCycle = 0;
    for (int v = 0; v < graph.size(); v++)
        if (!visited[v])
            dfsCycle(graph, v, visited, hasCycle);
    return !hasCycle;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, isDirected;
    cin >> vertexCount >> edgeCount >> isDirected;
    isDirected--;

    vector<vector<int>> graph(vertexCount);
    vector<int> inDegree(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        inDegree[b]++;

        if (!isDirected) {
            graph[b].push_back(a);
            inDegree[a]++;
        }
    }

    cout << checkTree(graph, inDegree, edgeCount, isDirected) << " ";
    cout << checkComplete(vertexCount, edgeCount, isDirected) << " ";
    cout << checkBipartite(graph, inDegree, isDirected) << " ";
    cout << checkDag(graph);
}