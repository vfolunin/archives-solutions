#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, int p, vector<int> &color, int cur, int limit) {
    cur = color[v] ? cur + 1 : 0;
    if (cur > limit)
        return 0;

    int res = v && graph[v].size() <= 1;
    for (int to : graph[v])
        if (to != p)
            res += dfs(graph, to, v, color, cur, limit);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, limit;
    cin >> vertexCount >> limit;

    vector<int> color(vertexCount);
    for (int &color : color)
        cin >> color;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << dfs(graph, 0, -1, color, 0, limit);
}