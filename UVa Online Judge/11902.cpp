#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int z, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (to != z && !visited[to])
            dfs(graph, to, z, visited);
}

void solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            int x;
            cin >> x;
            if (x)
                graph[i].push_back(j);
        }
    }

    vector<vector<int>> visited(vertexCount, vector<int>(vertexCount));
    for (int i = 0; i < vertexCount; i++)
        dfs(graph, 0, i, visited[i]);

    cout << "Case " << test << ":\n";
    for (int i = 0; i < vertexCount; i++) {
        cout << "+" << string(vertexCount * 2 - 1, '-') << "+\n";
        for (int j = 0; j < vertexCount; j++)
            cout << "|" << (visited[0][j] && (!i || !visited[i][j]) ? "Y" : "N");
        cout << "|\n";
    }
    cout << "+" << string(vertexCount * 2 - 1, '-') << "+\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}