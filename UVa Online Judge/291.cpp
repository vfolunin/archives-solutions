#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    struct Edge {
        int a, b, used;

        int other(int v) {
            return v == a ? b : a;
        }
    };

    vector<Edge> edges;
    vector<vector<int>> g;
    vector<int> path;

    void addEdge(int a, int b) {
        a--;
        b--;
        edges.push_back({ a, b, 0 });
        if (max(a, b) >= g.size())
            g.resize(max(a, b) + 1);
        g[a].push_back(edges.size() - 1);
        g[b].push_back(edges.size() - 1);
    }

    void dfs(int v = 0) {
        path.push_back(v);
        if (path.size() == 9) {
            for (int x : path)
                cout << x + 1;
            cout << "\n";
        } else {
            for (int &ei : g[v]) {
                if (edges[ei].used)
                    continue;
                int to = edges[ei].other(v);
                edges[ei].used = 1;
                dfs(to);
                edges[ei].used = 0;
            }
        }
        path.pop_back();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.dfs();
}