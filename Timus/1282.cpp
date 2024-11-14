#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, int depth, vector<int> &res) {
    for (int to : graph[v]) {
        int resTo = dfs(graph, to, depth + 1, res);
        if (res[v] == -2)
            res[v] = resTo;
        else if (depth % 2 == 0)
            res[v] = max(res[v], resTo);
        else
            res[v] = min(res[v], resTo);
    }
    return res[v];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    vector<int> res(vertexCount, -2);

    for (int v = 1; v < vertexCount; v++) {
        char type;
        int parent;
        cin >> type >> parent;

        graph[parent - 1].push_back(v);

        if (type == 'L')
            cin >> res[v];
    }

    dfs(graph, 0, 0, res);
    if (res[0] == 1)
        cout << "+";
    cout << res[0];
}