#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<int> usedLetter;
    vector<vector<int>> graph, graphR;
    vector<int> visited, order;

    Graph() {
        usedLetter.resize(26);
        graph.resize(26);
        graphR.resize(26);
        visited.resize(26);
    }

    void addEdge(int a, int b) {
        usedLetter[a] = usedLetter[b] = 1;
        graph[a].push_back(b);
        graphR[b].push_back(a);
    }

    void dfs1(int v) {
        visited[v] = 1;
        for (int to : graph[v])
            if (!visited[to])
                dfs1(to);
        order.push_back(v);
    }

    void dfs2(int v, int component, vector<vector<int>> &components) {
        visited[v] = 1;
        components[component].push_back(v);
        for (int to : graphR[v])
            if (!visited[to])
                dfs2(to, component, components);
    }

    vector<vector<int>> findScc() {
        for (int v = 0; v < graph.size(); v++)
            if (usedLetter[v] && !visited[v])
                dfs1(v);
        reverse(order.begin(), order.end());

        fill(visited.begin(), visited.end(), 0);
        int componentCount = 0;
        vector<vector<int>> components;

        for (int v : order) {
            if (usedLetter[v] && !visited[v]) {
                components.emplace_back();
                dfs2(v, componentCount++, components);
                sort(components.back().begin(), components.back().end());
            }
        }

        sort(components.begin(), components.end());
        return components;
    }
};

bool solve(int test) {
    int questionCount;
    cin >> questionCount;

    if (!questionCount)
        return 0;

    Graph graph;

    for (int i = 0; i < questionCount; i++) {
        string s(6, ' ');
        for (char &c : s)
            cin >> c;

        for (int i = 0; i < 5; i++)
            if (s[i] != s[5])
                graph.addEdge(s[i] - 'A', s[5] - 'A');
    }

    vector<vector<int>> scc = graph.findScc();

    if (test)
        cout << "\n";
    for (vector<int> &component : scc)
        for (int i = 0; i < component.size(); i++)
            cout << (char)(component[i] + 'A') << (i + 1 < component.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}