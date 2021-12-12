#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

map<string, int> bfs(map<string, vector<string>> &graph, const string &start) {
    map<string, int> dist;
    queue<string> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        string v = q.front();
        q.pop();

        for (string &to : graph[v]) {
            if (!dist.count(to)) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    map<string, vector<string>> graph;
    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    map<string, int> dist = bfs(graph, "*");

    cout << dist["Entrada"] + dist["Saida"] << "\n";
}