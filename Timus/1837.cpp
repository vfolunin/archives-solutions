#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> bfs(unordered_map<string, unordered_set<string>> &graph, const string &start) {
    unordered_map<string, int> dist;
    queue<string> q;

    dist[start];
    q.push(start);

    while (!q.empty()) {
        string v = q.front();
        q.pop();

        for (const string &to : graph[v]) {
            if (!dist.count(to) || dist[to] > dist[v] + 1) {
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

    int size;
    cin >> size;

    set<string> vertices;
    unordered_map<string, unordered_set<string>> graph;
    for (int i = 0; i < size; i++) {
        vector<string> curVertices(3);
        for (string &v : curVertices) {
            cin >> v;
            vertices.insert(v);
        }

        for (string &v : curVertices)
            for (string &to : curVertices)
                if (v != to)
                    graph[v].insert(to);
    }

    unordered_map<string, int> dist = bfs(graph, "Isenbaev");

    for (const string &v : vertices) {
        cout << v << " ";
        if (dist.count(v))
            cout << dist[v] << "\n";
        else
            cout << "undefined\n";
    }
}