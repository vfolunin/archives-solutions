#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Train {
    int from, to, startTime, rideTime;

    bool operator < (const Train &that) const {
        if (to < that.from || that.to < from)
            return 0;

        int common = max(from, that.from);
        return startTime + 1LL * (common - from) * rideTime <
               that.startTime + 1LL * (common - that.from) * that.rideTime;
    }
};

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

    int vertexCount;
    cin >> vertexCount;

    vector<Train> trains(vertexCount);
    for (auto &[from, to, startTime, speed] : trains)
        cin >> from >> to >> startTime >> speed;

    vector<vector<int>> graph(vertexCount);
    for (int a = 0; a < graph.size(); a++)
        for (int b = 0; b < graph.size(); b++)
            if (trains[a] < trains[b])
                graph[a].push_back(b);

    vector<int> visited(graph.size()), order;
    for (int v = 0; v < graph.size(); v++)
        if (!visited[v])
            dfs(graph, v, visited, order);
    reverse(order.begin(), order.end());

    for (int v : order)
        cout << v + 1 << " ";
}