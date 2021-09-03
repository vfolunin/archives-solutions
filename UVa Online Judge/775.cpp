#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(vector<vector<int>> &graph, vector<int> &visited, vector<int> &path) {
    if (path.size() == graph.size())
        return count(graph[path.back()].begin(), graph[path.back()].end(), path.front());

    for (int to : graph[path.back()]) {
        if (visited[to])
            continue;

        visited[to] = 1;
        path.push_back(to);

        if (rec(graph, visited, path))
            return 1;

        visited[to] = 0;
        path.pop_back();
    }

    return 0;
}

bool solve() {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;
    cin.ignore();

    vector<vector<int>> graph(vertexCount);
    while (1) {
        string line;
        getline(cin, line);
        if (line == "%")
            break;
        
        stringstream ss(line);
        int a, b;
        ss >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(vertexCount), path = { 0 };
    visited[0] = 1;

    if (rec(graph, visited, path)) {
        for (int v : path)
            cout << v + 1 << " ";
        cout << path[0] + 1 << "\n";
    } else {
        cout << "N\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}