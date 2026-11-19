#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &searchDepth) {
    for (int to : graph[v]) {
        searchDepth[to] = max(searchDepth[to], searchDepth[v] - 1);
        dfs(graph, to, searchDepth);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, queryCount;
    cin >> vertexCount >> queryCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 1; v < graph.size(); v++) {
        int parent;
        cin >> parent;
        parent--;

        graph[parent].push_back(v);
    }

    vector<int> searchDepth(graph.size());
    for (int i = 0; i < queryCount; i++) {
        int v, depth;
        cin >> v >> depth;
        v--;
        depth++;

        searchDepth[v] = max(searchDepth[v], depth);
    }

    dfs(graph, 0, searchDepth);

    cout << graph.size() - count(searchDepth.begin(), searchDepth.end(), 0);
}