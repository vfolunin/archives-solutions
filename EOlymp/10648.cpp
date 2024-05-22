#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    vector<int> inDegree(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    vector<int> dist(vertexCount, 1e9);
    set<int> q;
    for (int v = 0; v < vertexCount; v++) {
        if (!inDegree[v]) {
            dist[v] = 0;
            q.insert(v);
        }
    }
    
    while (!q.empty()) {
        if (q.size() > 1 && dist[*q.begin()] == dist[*next(q.begin())]) {
            set<int> res = { *q.begin(), *next(q.begin()) };
            for (int v = 0; res.size() < 3; v++)
                res.insert(v);

            for (int v : res)
                cout << v + 1 << " ";
            return 0;
        }

        int v = *q.begin();
        q.erase(q.begin());

        for (int to : graph[v]) {
            if (!--inDegree[to]) {
                dist[to] = dist[v] + 1;
                q.insert(to);
            }
        }
    }

    cout << -1;
}