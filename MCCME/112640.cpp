#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<vector<int>> &hasEdge, int v, int finish, vector<int> &visited, vector<int> &path, vector<vector<int>> &paths) {
    visited[v] = 1;
    path.push_back(v);

    if (v == finish) {
        paths.push_back(path);
    } else {
        for (int to = 0; to < hasEdge.size(); to++)
            if (hasEdge[v][to] && !visited[to])
                rec(hasEdge, to, finish, visited, path, paths);
    }

    visited[v] = 0;
    path.pop_back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> hasEdge(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> hasEdge[a][b];

    int start, finish;
    cin >> start >> finish;
    start--;
    finish--;

    vector<int> visited(vertexCount), path;
    vector<vector<int>> paths;
    rec(hasEdge, start, finish, visited, path, paths);

    cout << paths.size() << "\n";
    for (vector<int> &path : paths)
        for (int i = 0; i < path.size(); i++)
            cout << path[i] + 1 << (i + 1 < path.size() ? " " : "\n");
}