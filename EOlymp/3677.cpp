#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(vector<vector<int>> &graphA, int vFromA, vector<int> &visited, vector<int> &pairFromA) {
    visited[vFromA] = 1;

    for (int vFromB : graphA[vFromA]) {
        int &toFromA = pairFromA[vFromB];

        if (toFromA == -1 || !visited[toFromA] && dfs(graphA, toFromA, visited, pairFromA)) {
            toFromA = vFromA;
            return 1;
        }
    }

    return 0;
}

bool kuhn(vector<vector<int>> &graphA, int vertexCountB) {
    vector<int> pairFromA(vertexCountB, -1);

    for (int vFromA = 0; vFromA < graphA.size(); vFromA++) {
        vector<int> visited(graphA.size());
        dfs(graphA, vFromA, visited, pairFromA);
    }

    return find(pairFromA.begin(), pairFromA.end(), -1) == pairFromA.end();
}

bool can(vector<vector<int>> &matrix, int limit) {
    vector<vector<int>> graph(matrix.size());

    for (int a = 0; a < matrix.size(); a++)
        for (int b = 0; b < matrix.size(); b++)
            if (matrix[a][b] <= limit)
                graph[a].push_back(b);

    return kuhn(graph, graph.size());
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> matrix(size, vector<int>(size));
    for (int a = 0; a < matrix.size(); a++)
        for (int b = 0; b < matrix.size(); b++)
            cin >> matrix[a][b];

    int l = 0, r = 2e4;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(matrix, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}