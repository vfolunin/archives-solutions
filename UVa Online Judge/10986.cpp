#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int INF = 1e9;

void solve(int test) {
    int vertexCount, edgeCount, start, finish;
    cin >> vertexCount >> edgeCount >> start >> finish;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    vector<int> dist(vertexCount, INF);
    set<pair<int, int>> q;
    dist[start] = 0;
    q.insert({ dist[start], start });

    while (!q.empty()) {
        auto [_, v] = *q.begin();
        q.erase(q.begin());

        for (auto [to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    cout << "Case #" << test << ": ";
    if (dist[finish] != INF)
        cout << dist[finish] << "\n";
    else
        cout << "unreachable\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}