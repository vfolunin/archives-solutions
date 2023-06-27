#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

void dfs(unordered_map<string, set<string>> &graph, const string &v,
         unordered_map<string, int> &l, unordered_map<string, int> &r, int &timer) {
    l[v] = timer++;
    for (const string &to : graph[v])
        dfs(graph, to, l, r, timer);
    r[v] = timer++;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    unordered_map<string, set<string>> graph;
    unordered_map<string, int> inDegree;
    for (int i = 0; i < vertexCount - 1; i++) {
        string a, b;
        cin >> a >> b;
        graph[b].insert(a);
        inDegree[a]++;
    }

    unordered_map<string, int> l, r;
    int timer = 0;
    for (auto &[v, _] : graph)
        if (!inDegree[v])
            dfs(graph, v, l, r, timer);

    for (string a, b; cin >> a >> b; ) {
        if (l[a] <= l[b] && r[b] <= r[a])
            cout << "1 ";
        else if (l[b] <= l[a] && r[a] <= r[b])
            cout << "2 ";
        else
            cout << "0 ";
    }
}