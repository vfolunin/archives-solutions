#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

bool dfs(unordered_map<string, unordered_set<string>> &graph, const string &v, const string &finish) {
    if (v == finish)
        return 1;
    for (const string &to : graph[v])
        if (dfs(graph, to, finish))
            return 1;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int edgeCount, queryCount;
    cin >> edgeCount >> queryCount;

    unordered_map<string, unordered_set<string>> graph;
    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        cin >> a >> b >> b >> b >> b;

        graph[a].insert(b);
    }

    for (int i = 0; i < queryCount; i++) {
        string a, b;
        cin >> a >> b >> b >> b >> b;

        if (dfs(graph, a, b))
            cout << "Fact\n";
        else if (dfs(graph, b, a))
            cout << "Alternative Fact\n";
        else
            cout << "Pants on Fire\n";
    }
}