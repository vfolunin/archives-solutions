#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<int> &x, vector<int> &y, vector<int> &z, vector<int> &r, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to = 0; to < x.size(); to++) {
        if (visited[to] || z[to] >= z[v])
            continue;
        int dx = x[v] - x[to], dy = y[v] - y[to], dr = r[v] + r[to];
        if (dx * dx + dy * dy <= dr * dr)
            dfs(x, y, z, r, to, visited);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<int> x(vertexCount), y(vertexCount), z(vertexCount), r(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        cin >> x[v] >> y[v] >> z[v] >> r[v];

    vector<int> visited(vertexCount);
    dfs(x, y, z, r, 0, visited);

    cout << count(visited.begin(), visited.end(), 1) << "\n";
    for (int v = 0; v < vertexCount; v++)
        if (visited[v])
            cout << v + 1 << " ";
}