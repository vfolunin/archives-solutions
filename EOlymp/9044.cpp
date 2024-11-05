#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, order);
    order.push_back(v);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, start;
    cin >> vertexCount >> edgeCount >> start;
    start--;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        graph[a - 1].push_back(b - 1);
    }

    vector<int> visited(vertexCount), order;
    for (int v = 0; v < graph.size(); v++)
        if (!visited[v])
            dfs(graph, v, visited, order);
    reverse(order.begin(), order.end());

    vector<double> probability(vertexCount);
    probability[start] = 1;
    for (int v : order)
        for (int to : graph[v])
            probability[to] += probability[v] / graph[v].size();

    double maxProbability = 0;
    for (int v = 0; v < vertexCount; v++)
        if (graph[v].empty())
            maxProbability = max(maxProbability, probability[v]);

    for (int v = 0; v < vertexCount; v++)
        if (graph[v].empty() && probability[v] == maxProbability)
            cout << v + 1 << " ";
}