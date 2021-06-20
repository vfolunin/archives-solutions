#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> g;
    vector<int> visited, depth, upDepth;
    vector<pair<int, int>> targetPoints;

    void dfs(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];
        int childrenCount = 0;

        for (int to : g[v]) {
            if (to == p) {
                continue;
            } else if (!visited[to]) {
                dfs(to, v);
                upDepth[v] = min(upDepth[v], upDepth[to]);
                childrenCount += upDepth[to] >= depth[v];
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }

        targetPoints.push_back({ v, childrenCount + (p != -1) });
    }

    Graph(int vertexCount) {
        g.resize(vertexCount);
        visited.resize(vertexCount);
        depth.resize(vertexCount);
        upDepth.resize(vertexCount);
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<pair<int, int>> findTargetPoints() {
        for (int v = 0; v < g.size(); v++)
            if (!visited[v])
                dfs(v, -1);
        sort(targetPoints.begin(), targetPoints.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second || a.second == b.second && a.first < b.first;
        });
        return targetPoints;
    }
};

bool solve() {
    int vertexCount, targetCount;
    cin >> vertexCount >> targetCount;

    if (!vertexCount)
        return 0;

    Graph graph(vertexCount);
    while (1) {
        int a, b;
        cin >> a >> b;

        if (a == -1 && b == -1)
            break;

        graph.addEdge(a, b);
    }

    vector<pair<int, int>> targetPoints = graph.findTargetPoints();

    for (int i = 0; i < targetCount; i++)
        cout << targetPoints[i].first << " " << targetPoints[i].second << "\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}