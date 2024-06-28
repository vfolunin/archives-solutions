#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &colors, vector<vector<int>> &stacks, vector<int> &res) {
    res[v] = !stacks[colors[v]].empty() ? stacks[colors[v]].back() + 1 : -1;

    stacks[colors[v]].push_back(v);

    for (int to : graph[v])
        dfs(graph, to, colors, stacks, res);

    stacks[colors[v]].pop_back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, colorCount;
    cin >> vertexCount >> colorCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 1; v < vertexCount; v++) {
        int from;
        cin >> from;
        from--;
        graph[from].push_back(v);
    }

    vector<int> colors(vertexCount);
    for (int &color : colors) {
        cin >> color;
        color--;
    }

    vector<vector<int>> stacks(colorCount);
    vector<int> res(vertexCount);
    dfs(graph, 0, colors, stacks, res);

    for (int v : res)
        cout << v << " ";
}