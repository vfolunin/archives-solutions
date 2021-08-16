#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

bool dfsCycle(vector<vector<int>> &graph, int start, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (visited[to] == 1 && to == start)
            return 1;
        if (!visited[to] && dfsCycle(graph, start, to, visited))
            return 1;
    }
    visited[v] = 2;
    return 0;
}

void solve(int test) {
    int vertexCount, start1, start2;
    cin >> vertexCount >> start1 >> start2;
    start1--;
    start2--;

    vector<vector<int>> graph1(vertexCount);
    while (1) {
        int a, b;
        cin >> a >> b;
        
        if (a == -1 && b == -1)
            break;

        a--;
        b--;
        graph1[a].push_back(b);
    }

    cin.ignore();

    vector<vector<int>> graph2(vertexCount);
    while (1) {
        string line;
        getline(cin, line);

        if (line.empty())
            break;

        stringstream ss(line);

        int a, b;
        ss >> a >> b;

        a--;
        b--;
        graph2[a].push_back(b);
    }

    vector<int> visited1(vertexCount), visited2(vertexCount);
    dfs(graph1, start1, visited1);
    dfs(graph2, start2, visited2);

    if (test)
        cout << "\n";

    bool haveCommonRoom = 0;
    for (int v = 0; v < vertexCount; v++)
        haveCommonRoom |= visited1[v] && visited2[v];
    cout << (haveCommonRoom ? "Y " : "N ");

    vector<vector<int>> graph3(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        if (!visited1[v] && visited2[v])
            for (int to : graph2[v])
                if (!visited1[to] && visited2[to])
                    graph3[v].push_back(to);

    vector<int> visited3(vertexCount);
    cout << (dfsCycle(graph3, start2, start2, visited3) ? "Y\n" : "N\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}