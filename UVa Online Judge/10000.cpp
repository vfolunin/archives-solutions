#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> dfs(vector<vector<int>> &graph, int v, vector<int> &dist, vector<int> &finish) {
    if (dist[v] != -1)
        return { dist[v], finish[v] };
    dist[v] = 0;
    finish[v] = v;
    for (int to : graph[v]) {
        auto [d, f] = dfs(graph, to, dist, finish);
        if (d + 1 > dist[v] || d + 1 == dist[v] && f < finish[v]) {
            dist[v] = d + 1;
            finish[v] = f;
        }
    }
    return { dist[v], finish[v] };
}

bool solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    int startVertex;
    cin >> startVertex;
    startVertex--;

    vector<vector<int>> graph(vertexCount);
    while (1) {
        int a, b;
        cin >> a >> b;
        if (!a && !b)
            break;
        graph[a - 1].push_back(b - 1);
    }

    vector<int> dist(vertexCount, -1), finish(vertexCount, -1);
    auto [distance, finishVertex] = dfs(graph, startVertex, dist, finish);
  
    cout << "Case " << test << ": ";
    cout << "The longest path from " << startVertex + 1;
    cout << " has length " << distance << ", finishing at " << finishVertex + 1 << ".\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}