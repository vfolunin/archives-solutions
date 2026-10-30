#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, targetVertex, startVertex;
    cin >> vertexCount >> edgeCount >> targetVertex >> startVertex;
    targetVertex--;
    startVertex--;

    vector<vector<int>> graph(vertexCount);
    vector<int> startDegree(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
        startDegree[a]++;
        startDegree[b]++;
    }

    vector<int> curDegree = startDegree;
    vector<int> left(vertexCount);
    queue<int> q;
    q.push(startVertex);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        left[v] = 1;

        for (int to : graph[v]) {
            curDegree[to]--;
            if (!left[to] && curDegree[to] * 2 <= startDegree[to])
                q.push(to);
        }
    }

    cout << (left[targetVertex] ? "leave" : "stay");
}