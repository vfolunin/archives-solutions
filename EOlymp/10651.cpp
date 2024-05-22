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

    set<int> q;
    for (int v = 0; v < vertexCount; v++)
        if (!inDegree[v])
            q.insert(v);

    vector<int> order;
    while (!q.empty()) {
        int v = *q.begin();
        order.push_back(v);
        q.erase(q.begin());

        for (int to : graph[v])
            if (!--inDegree[to])
                q.insert(to);
    }

    if (order.size() == vertexCount) {
        for (int v : order)
            cout << v + 1 << " ";
    } else {
        cout << -1;
    }
}