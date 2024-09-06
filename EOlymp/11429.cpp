#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, vector<int> &size) {
    size[v] = 1;
    for (int to : graph[v])
        size[v] += dfs(graph, to, size);
    return size[v];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 1; v < vertexCount; v++) {
        int p;
        cin >> p;
        graph[p - 1].push_back(v);
    }

    vector<int> size(vertexCount);
    dfs(graph, 0, size);

    for (int s : size)
        cout << s - 1 << " ";
}