#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int p, vector<vector<int>> &matching) {
    int maxDelta = -1e9;
    for (int to : graph[v]) {
        if (to != p) {
            dfs(graph, to, v, matching);
            matching[v][0] += matching[to][1];
            matching[v][1] += matching[to][1];
            maxDelta = max(maxDelta, 1 + matching[to][0] - matching[to][1]);
        }
    }
    if (maxDelta != -1e9)
        matching[v][1] += maxDelta;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    vector<vector<int>> matching(vertexCount, vector<int>(2));
    dfs(graph, 0, -1, matching);

    cout << matching[0][1];
}