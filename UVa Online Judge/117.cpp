#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &graph, int a, int b) {
    vector<int> dist(1000, 1e9);
    dist[a] = 0;
    set<pair<int, int>> q = { {dist[a], a} };

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

    return dist[b];
}

bool solve() {
    vector<int> degree(26);
    vector<vector<pair<int, int>>> graph(26);
    int res = 0;

    while (1) {
        string line;
        if (!(cin >> line))
            return 0;

        if (line == "deadend")
            break;

        int a = line.front() - 'a';
        int b = line.back() - 'a';
        int w = line.size();

        degree[a]++;
        degree[b]++;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
        res += w;
    }

    int a = -1, b = -1;
    for (int v = 0; v < 26; v++) {
        if (degree[v] % 2) {
            if (a == -1)
                a = v;
            else
                b = v;
        }
    }

    if (a != -1 && b != -1)
        res += dijkstra(graph, a, b);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}