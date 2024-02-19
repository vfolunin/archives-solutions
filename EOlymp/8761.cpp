#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int &t, vector<int> &tIn, vector<int> &tOut) {
    tIn[v] = t++;

    for (int to : graph[v])
        if (!tIn[to])
            dfs(graph, to, t, tIn, tOut);

    tOut[v] = t++;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start;
    cin >> start;
    start--;

    int t = 1;
    vector<int> tIn(vertexCount), tOut(vertexCount);
    dfs(graph, start, t, tIn, tOut);

    for (int v = 0; v < vertexCount; v++)
        cout << tIn[v] << " " << tOut[v] << "\n";
}