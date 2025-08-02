#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> a(vertexCount);
    for (int &value : a)
        cin >> value;

    vector<int> visited(graph.size());
    set<pair<int, int>> q;
    int res = 0;

    visited[0] = 1;
    q.insert({ a[0], 0 });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (v && res <= a[v])
            break;

        res += a[v];

        for (int to : graph[v]) {
            if (!visited[to]) {
                visited[to] = 1;
                q.insert({ a[to], to });
            }
        }
    }

    cout << res;
}