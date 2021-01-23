#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    map<string, set<string>> g, gr;
    set<string> visited;
    vector<string> order;
    vector<vector<string>> scc;

    void addEdge(const string &a, const string &b) {
        g[a].insert(b);
        gr[b].insert(a);
    }

    void dfs1(const string &v) {
        visited.insert(v);
        for (const string &to : g[v])
            if (!visited.count(to))
                dfs1(to);
        order.push_back(v);
    }

    void dfs2(const string &v) {
        scc.back().push_back(v);
        visited.insert(v);
        for (const string &to : gr[v])
            if (!visited.count(to))
                dfs2(to);
    }

    void findScc() {
        for (const auto &[v, _] : g)
            if (!visited.count(v))
                dfs1(v);
        reverse(order.begin(), order.end());

        visited.clear();
        for (const string &v : order) {
            if (!visited.count(v)) {
                scc.emplace_back();
                dfs2(v);
            }
        }
    }
};


bool solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    Graph graph;

    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    graph.findScc();

    if (test > 1)
        cout << "\n";
    cout << "Calling circles for data set " << test << ":\n";
    for (vector<string> &scc : graph.scc)
        for (int i = 0; i < scc.size(); i++)
            cout << scc[i] << (i + 1 < scc.size() ? ", " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}