#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

struct Graph {
    unordered_map<string, unordered_set<string>> graph;
    unordered_map<string, vector<string>> ancestor;
    unordered_map<string, int> inDegree, l, r;
    int timer = 0;

    void addEdge(string a, string b) {
        graph[a].insert(b);
        inDegree[b]++;
    }

    void dfs(const string &v, const string &parent) {
        l[v] = timer++;

        ancestor[v].resize(20);
        ancestor[v][0] = parent;
        for (int i = 1; i < ancestor[v].size(); i++)
            ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];

        for (const string &to : graph[v])
            dfs(to, v);

        r[v] = timer++;
    }

    void prepare() {
        for (auto &[v, _] : graph)
            if (!inDegree[v])
                dfs(v, v);
    }

    bool isAncestor(string &a, string &b) {
        return l[a] <= l[b] && r[b] <= r[a];
    }

    string lca(string &a, string &b) {
        if (isAncestor(a, b))
            return a;
        if (isAncestor(b, a))
            return b;

        for (int i = ancestor[a].size() - 1; i >= 0; i--)
            if (!isAncestor(ancestor[a][i], b))
                a = ancestor[a][i];

        return ancestor[a][0];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    Graph graph;

    for (int i = 0; i < vertexCount - 1; i++) {
        string a, b;
        cin >> a >> b;
        graph.addEdge(b, a);
    }

    graph.prepare();

    for (string a, b; cin >> a >> b; )
        cout << graph.lca(a, b) << "\n";
}