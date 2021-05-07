#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(vector<vector<int>> &g, int v, int len, vector<int> &path, vector<int> &used) {
    if (path.size() == len) {
        cout << "(";
        for (int i = 0; i < path.size(); i++)
            cout << path[i] + 1 << (i + 1 < path.size() ? "," : ")\n");
        return 1;
    }

    bool res = 0;
    for (int to = 0; to < g.size(); to++) {
        if (g[v][to] && !used[to]) {
            path.push_back(to);
            used[to] = 1;
            res |= rec(g, to, len, path, used);
            path.pop_back();
            used[to] = 0;
        }
    }
    return res;
}

bool solve(int test) {
    int vertexCount, pathLen;
    cin >> vertexCount >> pathLen;

    vector<vector<int>> g(vertexCount, vector<int>(vertexCount));
    for (int i = 0; i < vertexCount; i++)
        for (int j = 0; j < vertexCount; j++)
            cin >> g[i][j];

    vector<int> path = {0};
    vector<int> used(vertexCount);
    used[0] = 1;

    if (test)
        cout << "\n";
    if (!rec(g, 0, pathLen + 1, path, used))
        cout << "no walk of length " << pathLen << "\n";

    int sep;
    return !!(cin >> sep);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}