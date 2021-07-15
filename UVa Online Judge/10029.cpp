#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

void addEdges(string &s, int v, vector<string> &vertexName, unordered_map<string, vector<int>> &vertexId, vector<vector<int>> &graph) {
    if (vertexId.count(s) && s <= vertexName[v])
        for (int from : vertexId[s])
            if (from < v)
                graph[from].push_back(v);
}

void dfs(vector<vector<int>> &graph, int v, vector<int> &dist) {
    dist[v] = 1;
    for (int to : graph[v]) {
        if (!dist[to])
            dfs(graph, to, dist);
        dist[v] = max(dist[v], 1 + dist[to]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> vertexName;
    string s;
    while (cin >> s)
        vertexName.push_back(s);
    sort(vertexName.begin(), vertexName.end());

    unordered_map<string, vector<int>> vertexId;
    for (int v = 0; v < vertexName.size(); v++)
        vertexId[vertexName[v]].push_back(v);

    vector<vector<int>> graph(vertexName.size());
    for (int v = 0; v < vertexName.size(); v++) {
        for (int i = 0; i < vertexName[v].size(); i++) {
            string s = vertexName[v].substr(0, i) + vertexName[v].substr(i + 1);
            addEdges(s, v, vertexName, vertexId, graph);

            for (char c = 'a'; c <= 'z'; c++) {
                string s = vertexName[v].substr(0, i) + c + vertexName[v].substr(i + 1);
                addEdges(s, v, vertexName, vertexId, graph);

                s = vertexName[v].substr(0, i) + c + vertexName[v].substr(i);
                addEdges(s, v, vertexName, vertexId, graph);
            }
        }
    }

    vector<int> dist(vertexName.size());
    for (int v = 0; v < vertexName.size(); v++)
        if (!dist[v])
            dfs(graph, v, dist);

    cout << *max_element(dist.begin(), dist.end()) << "\n";
}