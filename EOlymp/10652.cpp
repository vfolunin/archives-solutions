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

    bool isUnique = 1;
    int size = 0;
    while (!q.empty()) {
        int v = *q.begin();
        isUnique &= q.size() == 1;
        size++;
        q.erase(q.begin());

        for (int from : graph[v])
            if (!--inDegree[from])
                q.insert(from);
    }

    if (size == vertexCount)
        cout << (isUnique ? "Yes" : "No");
    else
        cout << -1;
}