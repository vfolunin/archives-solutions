#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int vertexCount, edgeCount, time, startVertex;
    cin >> vertexCount >> startVertex >> time >> edgeCount;
    
    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[b - 1].push_back({ a - 1, w });
    }

    vector<int> dist(vertexCount, 1e9);
    dist[startVertex - 1] = 0;
    set<pair<int, int>> q = { {0, startVertex - 1} };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    int res = 0;
    for (int v = 0; v < vertexCount; v++)
        res += dist[v] <= time;

    if (test)
        cout << "\n";
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}