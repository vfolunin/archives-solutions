#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph;

    Graph(int vertexCount) {
        graph.resize(vertexCount);
    }

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    set<int> bestBlack, black;
    void rec(int v) {
        if (v == graph.size()) {
            if (bestBlack.size() < black.size())
                bestBlack = black;
            return;
        }

        bool canBeBlack = 1;
        for (int to : graph[v])
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
    for (int v : graph.bestBlack)
        cout << v + 1 << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}