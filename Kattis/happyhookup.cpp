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
        a--;
        b--;

        graph[a].push_back(b);
    }

    int startA, startB;
    cin >> startA >> startB;
    startA--;
    startB--;

    vector<int> visitedA(graph.size());
    dfs(graph, startA, visitedA);
    vector<int> visitedB(graph.size());
    dfs(graph, startB, visitedB);

    for (int v = 0; v < graph.size(); v++) {
        if (visitedA[v] && visitedB[v]) {
            cout << "yes\n" << v + 1;
            return 0;
        }
    }
    
    cout << "no";
}