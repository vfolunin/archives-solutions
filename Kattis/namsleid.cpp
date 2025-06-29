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

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount), graphR(vertexCount);
    vector<int> inDegree(vertexCount);

    for (int v = 0; v < vertexCount; v++) {
        cin >> inDegree[v];

        for (int i = 0; i < inDegree[v]; i++) {
            int from;
            cin >> from;
            from--;

            graph[from].push_back(v);
            graphR[v].push_back(from);
        }
    }

    vector<int> level(vertexCount);
    set<int> q;
    for (int v = 0; v < vertexCount; v++)
        if (!inDegree[v])
            q.insert(v);

    vector<vector<int>> order;
    for (int i = 0; i < vertexCount; i++) {
        if (q.empty()) {
            cout << "Omogulegt!";
            return 0;
        }

        int v = *q.begin();
        q.erase(q.begin());

        for (int from : graphR[v])
            level[v] = max(level[v], level[from] + 1);

        if (level[v] == order.size())
            order.emplace_back();
        order.back().push_back(v);

        for (int to : graph[v])
            if (!--inDegree[to])
                q.insert(to);
    }

    cout << "Mogulegt!\n" << order.size() << "\n";
    for (vector<int> &levelOrder : order) {
        cout << levelOrder.size() << " ";
        for (int v : levelOrder)
            cout << v + 1 << " ";
        cout << "\n";
    }
}