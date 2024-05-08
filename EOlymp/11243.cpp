#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &in, vector<int> &out, int &timer) {
    in[v] = ++timer;

    for (int to : graph[v])
        if (!in[to])
            dfs(graph, to, in, out, timer);

    out[v] = ++timer;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        int degree;
        cin >> degree;

        for (int i = 0; i < degree; i++) {
            int to;
            cin >> to;

            graph[v].push_back(to - 1);
        }
    }

    vector<int> in(vertexCount), out(vertexCount);
    int timer = 0;

    for (int v = 0; v < vertexCount; v++)
        if (!in[v])
            dfs(graph, v, in, out, timer);

    for (int v = 0; v < vertexCount; v++)
        cout << in[v] << " " << out[v] << "\n";
}