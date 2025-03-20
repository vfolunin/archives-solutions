#include <iostream>
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

void solve() {
    int edgeCount;
    cin >> edgeCount;

    vector<vector<int>> graph(26);
    vector<int> inDegree(26), outDegree(26);

    for (int i = 0; i < edgeCount; i++) {
        string edge;
        cin >> edge;

        graph[edge.front() - 'a'].push_back(edge.back() - 'a');
        inDegree[edge.back() - 'a']++;
        outDegree[edge.front() - 'a']++;
    }

    int start = -1, finish = -1;
    for (int v = 0; v < 26; v++) {
        if (inDegree[v] == outDegree[v])
            continue;
        if (start == -1 && inDegree[v] + 1 == outDegree[v]) {
            start = v;
        } else if (finish == -1 && inDegree[v] == 1 + outDegree[v]) {
            finish = v;
        } else {
            cout << "The door cannot be opened.\n";
            return;
        }
    }

    if (start == -1)
        while (!inDegree[++start]);
    vector<int> visited(26);
    dfs(graph, start, visited);

    for (int v = 0; v < 26; v++) {
        if (!visited[v] && (inDegree[v] || outDegree[v])) {
            cout << "The door cannot be opened.\n";
            return;
        }
    }

    cout << "Ordering is possible.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}