#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &graph, int v, vector<int> &dist) {
    for (auto &[to, w] : graph[v]) {
        if (dist[to] == -1) {
            dist[to] = dist[v] + w;
            dfs(graph, to, dist);
        }
    }
}

bool solve() {
    vector<vector<pair<int, int>>> graph;
    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;

        stringstream ss(line);
        int a, b, w;
        ss >> a >> b >> w;

        if (a > graph.size())
            graph.resize(a);
        if (b > graph.size())
            graph.resize(b);

        graph[a - 1].push_back({ b - 1, w });
        graph[b - 1].push_back({ a - 1, w });
    }

    if (graph.empty())
        return 0;

    vector<int> dist(graph.size(), -1);
    dist[0] = 0;
    dfs(graph, 0, dist);

    int v = max_element(dist.begin(), dist.end()) - dist.begin();
    fill(dist.begin(), dist.end(), -1);
    dist[v] = 0;
    dfs(graph, v, dist);

    cout << *max_element(dist.begin(), dist.end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}