#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> bfs(vector<vector<int>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

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

    return dist;
}

void solve() {
    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        int degree;
        cin >> degree;
        graph[v].resize(degree);
        for (int &to : graph[v]) {
            cin >> to;
            to--;
        }
    }

    vector<int> dist = bfs(graph, 0);
    int a = max_element(dist.begin(), dist.end()) - dist.begin();

    vector<int> distA = bfs(graph, a);
    int b = max_element(distA.begin(), distA.end()) - distA.begin();
    int diameter = distA[b];

    cout << (vertexCount - 1) * 2 - diameter << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}