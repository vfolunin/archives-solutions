#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &graph, int startCount) {
    vector<int> dist(graph.size(), 1e9);
    queue<int> q;

    for (int v = 0; v < startCount; v++) {
        dist[v] = 0;
        q.push(v);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    int res = 0;
    for (int d : dist)
        res += d;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, startCount;
    cin >> vertexCount >> startCount;
    cin.ignore();

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        for (int to; ss >> to; )
            graph[v].push_back(to - 1);
    }

    cout << bfs(graph, startCount);
}