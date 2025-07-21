#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

void bfs(unordered_map<string, vector<pair<string, double>>> graph, string &start, double startValue, string &finish) {
    unordered_map<string, double> dist;
    queue<string> q;

    dist[start] = startValue;
    q.push(start);

    while (!q.empty()) {
        string v = q.front();
        q.pop();

        if (v == finish) {
            cout.precision(20);
            cout << dist[v] << "\n";
            return;
        }

        for (auto &[to, factor] : graph[v]) {
            if (!dist.count(to)) {
                dist[to] = dist[v] * factor;
                q.push(to);
            }
        }
    }

    cout << "impossible\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int edgeCount, queryCount;
    cin >> edgeCount >> queryCount;

    unordered_map<string, vector<pair<string, double>>> graph;
    for (int i = 0; i < edgeCount; i++) {
        double aValue, bValue;
        string a, b;
        cin >> aValue >> a >> b >> bValue >> b;

        graph[a].push_back({ b, bValue / aValue });
        graph[b].push_back({ a, aValue / bValue });
    }

    for (int i = 0; i < queryCount; i++) {
        double aValue;
        string a, b;
        cin >> aValue >> a >> b >> b;

        bfs(graph, a, aValue, b);
    }
}