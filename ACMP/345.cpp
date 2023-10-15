#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getId(string &s) {
    static map<string, int> ids;
    if (!ids.count(s))
        ids[s] = ids.size();
    return ids[s];
}

bool dfs(vector<vector<int>> &graph, int start, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (to == start || !visited[to] && dfs(graph, start, to, visited))
            return 1;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    vector<int> starts(vertexCount);

    for (int &v : starts) {
        string vName;
        int adjCount;
        cin >> vName >> adjCount;

        v = getId(vName);

        for (int j = 0; j < adjCount; j++) {
            string toName;
            cin >> toName;

            graph[v].push_back(getId(toName));
        }

        string separator;
        cin >> separator;
    }

    for (int start : starts) {
        vector<int> visited(vertexCount);
        cout << (dfs(graph, start, start, visited) ? "YES\n" : "NO\n");
    }
}