#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> dfs(vector<set<int>> &graph, int v, vector<int> &visited, int color, int &fail) {
    int k1 = color == 1, k2 = color == 2;
    visited[v] = color;
    for (int to : graph[v]) {
        if (!visited[to]) {
            auto [to1, to2] = dfs(graph, to, visited, 3 - color, fail);
            k1 += to1;
            k2 += to2;
        } else {
            fail |= visited[to] == color;
        }
    }
    return { k1, k2 };
}

void solve() {
    int vertexCount;
    cin >> vertexCount;

    vector<set<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        int degree;
        cin >> degree;

        for (int i = 0; i < degree; i++) {
            int to;
            cin >> to;
            to--;

            if (to < vertexCount) {
                graph[v].insert(to);
                graph[to].insert(v);
            }
        }
    }

    int res = 0;
    vector<int> visited(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        if (!visited[v]) {
            int fail = 0;
            auto [k1, k2] = dfs(graph, v, visited, 1, fail);
            if (!fail)
                res += max(k1, k2);
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}