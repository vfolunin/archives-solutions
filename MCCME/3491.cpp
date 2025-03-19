#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

map<string, int> bfs(map<string, set<string>> &graph, string &start) {
    map<string, int> dist;
    queue<string> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        string v = q.front();
        q.pop();

        for (const string &to : graph[v]) {
            if (!dist.count(to)) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist;
}

void solve(int test) {
    int edgeCount;
    cin >> edgeCount;

    map<string, set<string>> graph;
    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        cin >> a >> b;

        graph[a].insert(b);
        graph[b].insert(a);
    }

    string start;
    cin >> start;

    if (test)
        cout << "===\n";
    for (auto &[v, dist] : bfs(graph, start))
        cout << v << " " << dist << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}