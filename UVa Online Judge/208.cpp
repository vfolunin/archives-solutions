#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

void rec(vector<vector<int>> &graph, int v, int target, vector<int> &visited, vector<int> &path, vector<vector<int>> &paths) {
    visited[v] = 1;
    path.push_back(v);

    if (v == target) {
        paths.push_back(path);
    } else {
        for (int to : graph[v])
            if (!visited[to])
                rec(graph, to, target, visited, path, paths);
    }

    path.pop_back();
    visited[v] = 0;
}

bool solve(int test) {
    int target;
    if (!(cin >> target))
        return 0;
    target--;

    vector<vector<int>> graph(20);
    while (1) {
        int a, b;
        cin >> a >> b;

        if (!a && !b)
            break;

        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    vector<vector<int>> paths;
    vector<int> visited(20);
    dfs(graph, 0, visited);

    if (visited[target]) {
        vector<int> path;
        fill(visited.begin(), visited.end(), 0);
        rec(graph, 0, target, visited, path, paths);
        sort(paths.begin(), paths.end());
    }

    cout << "CASE " << test << ":\n";
    for (vector<int> &path : paths)
        for (int i = 0; i < path.size(); i++)
            cout << path[i] + 1 << (i + 1 < path.size() ? " " : "\n");
    cout << "There are " << paths.size() << " routes from the firestation to streetcorner " << target + 1 << ".\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}