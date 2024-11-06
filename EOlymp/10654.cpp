#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int p, vector<int> &color, vector<int> &count, vector<int> &res) {
    if (!count[color[v]])
        res.push_back(v);

    count[color[v]]++;

    for (int to : graph[v])
        if (to != p)
            dfs(graph, to, v, color, count, res);

    count[color[v]]--;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<int> color(vertexCount);
    for (int &c : color) {
        cin >> c;
        c--;
    }

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> count(1e5), res;
    dfs(graph, 0, -1, color, count, res);
    sort(res.begin(), res.end());

    for (int v : res)
        cout << v + 1 << "\n";
}