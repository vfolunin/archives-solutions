#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int p, vector<vector<int>> &cost) {
    cost[v][1] = 1;
    for (int to : graph[v]) {
        if (to != p) {
            dfs(graph, to, v, cost);
            cost[v][0] += cost[to][1];
            cost[v][1] += min(cost[to][0], cost[to][1]);
        }
    }
}

bool solve() {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        int v;
        cin >> v;
        cin.ignore(2);
        
        int degree;
        cin >> degree;
        cin.ignore();

        for (int j = 0; j < degree; j++) {
            int to;
            cin >> to;

            graph[v].push_back(to);
            graph[to].push_back(v);
        }
    }

    vector<vector<int>> cost(vertexCount, vector<int>(2));
    dfs(graph, 0, -1, cost);

    cout << min(cost[0][0], cost[0][1]) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}