#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> bfs(vector<vector<int>> &graph, int v) {
    vector<int> dist(graph.size(), -1);
    dist[v] = 0;
    vector<int> distCount = { 0 };

    queue<int> q;
    q.push(v);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
                if (dist[to] == distCount.size())
                    distCount.push_back(1);
                else
                    distCount[dist[to]]++;
            }
        }
    }

    int day = max_element(distCount.begin(), distCount.end()) - distCount.begin();
    return { distCount[day], day };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        int adjCount;
        cin >> adjCount;
        graph[v].resize(adjCount);
        for (int &to : graph[v])
            cin >> to;
    }

    int testCount;
    cin >> testCount;

    for (int i = 0; i < testCount; i++) {
        int v;
        cin >> v;

        auto [count, day] = bfs(graph, v);
        cout << count;
        if (count)
            cout << " " << day;
        cout << "\n";
    }
}