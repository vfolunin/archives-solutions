#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int p, vector<int> &d0, vector<int> &d1) {
    d0[v] = 0;
    d1[v] = 1;
    for (int to : graph[v]) {
        if (to == p)
            continue;
        dfs(graph, to, v, d0, d1);
        d0[v] += d1[to];
        d1[v] += min(d0[to], d1[to]);
    }
}

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> graph(vertexCount);
    for (vector<int> &row : graph) {
        int degree;
        cin >> degree;
        row.resize(degree);

        for (int &v : row) {
            cin >> v;
            v--;
        }
    }

    vector<int> d0(vertexCount), d1(vertexCount);
    dfs(graph, 0, -1, d0, d1);

    cout << max(1, min(d0[0], d1[0])) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}