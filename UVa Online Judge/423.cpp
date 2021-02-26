#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int a = 1; a < vertexCount; a++) {
        for (int b = 0; b < a; b++) {
            string ws;
            cin >> ws;
            if (ws != "x") {
                int w = stoi(ws);
                graph[a].emplace_back(b, w);
                graph[b].emplace_back(a, w);
            }
        }
    }

    vector<int> dist(vertexCount, 1e9);
    dist[0] = 0;
    set<pair<int, int>> q = { {0, 0} };

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

    cout << *max_element(dist.begin(), dist.end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}