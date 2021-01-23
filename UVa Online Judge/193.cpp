#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> g;

    Graph(int vertexCount) {
        g.resize(vertexCount);
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    set<int> bestBlack, black;
    void rec(int v) {
        if (v == g.size()) {
            if (bestBlack.size() < black.size())
                bestBlack = black;
            return;
        }

        bool canBeBlack = 1;
        for (int to : g[v])
            canBeBlack &= !black.count(to);

        if (canBeBlack) {
            black.insert(v);
            rec(v + 1);
            black.erase(v);
        }
        rec(v + 1);
    }
};

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    graph.rec(0);

    cout << graph.bestBlack.size() << "\n";
    for (auto it = graph.bestBlack.begin(); it != graph.bestBlack.end(); it++)
        cout << *it + 1 << (next(it) != graph.bestBlack.end() ? ' ' : '\n');
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}