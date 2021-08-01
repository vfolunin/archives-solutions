#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<vector<vector<int>>> &res) {
    visited[v] = 1;

    for (int to : graph[v]) {
        if (visited[to])
            continue;

        dfs(graph, to, visited, res);

        res[v][0][0] += res[to][1][0];
        res[v][0][1] += res[to][1][1];
        res[v][0][2] += res[to][1][2] + 1;

        if (res[to][1][0] < res[to][0][0] ||
            res[to][1][0] == res[to][0][0] && res[to][1][1] + 1 > res[to][0][1]) {
            res[v][1][0] += res[to][1][0];
            res[v][1][1] += res[to][1][1] + 1;
            res[v][1][2] += res[to][1][2];
        } else {
            res[v][1][0] += res[to][0][0];
            res[v][1][1] += res[to][0][1];
            res[v][1][2] += res[to][0][2] + 1;
        }
    }

    res[v][1][0]++;
}

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<vector<int>>> res(vertexCount, vector<vector<int>>(2, vector<int>(3)));
    vector<int> visited(vertexCount), answer(3);

    for (int v = 0; v < vertexCount; v++) {
        if (visited[v])
            continue;

        dfs(graph, v, visited, res);

        if (res[v][0][0] < res[v][1][0] ||
            res[v][0][0] == res[v][1][0] && res[v][0][1] > res[v][1][1]) {
            answer[0] += res[v][0][0];
            answer[1] += res[v][0][1];
            answer[2] += res[v][0][2];
        } else {
            answer[0] += res[v][1][0];
            answer[1] += res[v][1][1];
            answer[2] += res[v][1][2];
        }
    }

    cout << answer[0] << " " << answer[1] << " " << answer[2] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}