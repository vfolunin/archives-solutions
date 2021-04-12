#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> bfs(vector<vector<int>> &graph, int v) {
    vector<int> dist(graph.size(), -1);
    queue<int> q;

    dist[v] = 0;
    q.push(v);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist;
}

void solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        int vertexIndex, degree;
        cin >> vertexIndex >> degree;
        graph[v].resize(degree);
        for (int &to : graph[v])
            cin >> to;
    }

    int a, b;
    cin >> a >> b;

    if (test)
        cout << "\n";
    cout << a << " " << b << " " << bfs(graph, a)[b] - 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}