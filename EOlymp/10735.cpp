#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> graph, int v, int parent, vector<int> &depth, vector<int> &upDepth) {
    depth[v] = parent != -1 ? depth[parent] + 1 : 0;
    upDepth[v] = depth[v];

    int cutPointCount = 0, isCutPoint = 0, childCount = 0;
    for (int to : graph[v]) {
        if (depth[to] == -1) {
            childCount++;
            cutPointCount += dfs(graph, to, v, depth, upDepth);
            upDepth[v] = min(upDepth[v], upDepth[to]);
            if (parent != -1 && upDepth[to] >= depth[v])
                isCutPoint = 1;
        } else if (to != parent) {
            upDepth[v] = min(upDepth[v], depth[to]);
        }
    }

    if (parent == -1 && childCount > 1)
        isCutPoint = 1;

    return cutPointCount + isCutPoint;
}

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> graph(vertexCount);
    while (1) {
        int v;
        cin >> v;

        if (!v)
            break;

        while (1) {
            int to;
            cin >> to;

            graph[v - 1].push_back(to - 1);
            graph[to - 1].push_back(v - 1);

            if (cin.get() == '\n')
                break;
        }
    }

    vector<int> depth(vertexCount, -1), uoDepth(vertexCount, -1);
    int res = dfs(graph, 0, -1, depth, uoDepth);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}