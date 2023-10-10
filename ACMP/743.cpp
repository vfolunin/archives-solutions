#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Compressor {
    unordered_map<string, int> id;

    int getId(string &s) {
        if (!id.count(s))
            id[s] = id.size();
        return id[s];
    }
};

int bfs(vector<vector<int>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == finish)
            return dist[v];

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int edgeCount;
    cin >> edgeCount;

    Compressor compressor;
    vector<vector<int>> graph(100);

    for (int i = 0; i < edgeCount; i++) {
        string sa, arrow, sb;
        cin >> sa >> arrow >> sb;

        int a = compressor.getId(sa);
        int b = compressor.getId(sb);

        graph[a].push_back(b);
    }

    string sa, sb;
    cin >> sa >> sb;

    int a = compressor.getId(sa);
    int b = compressor.getId(sb);

    cout << bfs(graph, a, b);
}