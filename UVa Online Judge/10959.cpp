#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> dist(vertexCount, 1e9);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] == 1e9) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    if (test)
        cout << "\n";
    for (int v = 1; v < vertexCount; v++)
        cout << dist[v] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}