#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string dfs(map<string, vector<string>> &graph, map<string, string> &type, string v) {
    if (type.count(v))
        return type[v];

    string a = dfs(graph, type, graph[v][0]);
    string b = dfs(graph, type, graph[v][1]);

    if (a == "non-existent" && b != "dominant" || a != "dominant" && b == "non-existent")
        return type[v] = "non-existent";
    if (a == "dominant" && b != "non-existent" || a != "non-existent" && b == "dominant")
        return type[v] = "dominant";
    return type[v] = "recessive";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    map<string, vector<string>> graph;
    map<string, string> type;

    for (int i = 0; i < vertexCount; i++) {
        string a, b;
        cin >> a >> b;

        if (b == "non-existent" || b == "recessive" || b == "dominant")
            type[a] = b;
        else
            graph[b].push_back(a);
    }

    for (auto &[v, _] : graph)
        dfs(graph, type, v);

    for (auto &[v, t] : type)
        cout << v << " " << t << "\n";
}