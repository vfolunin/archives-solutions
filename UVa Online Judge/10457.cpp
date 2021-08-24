#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

struct Edge {
    int a, b, w;

    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

int getCost(int vertexCount, vector<Edge> &edges, int from, int start, int finish) {
    DSU dsu(vertexCount);
    int i, res = 0;
    for (i = from; i < edges.size() && !dsu.connected(start, finish); i++) {
        dsu.merge(edges[i].a, edges[i].b);
        res = edges[i].w - edges[from].w;
    }
    return dsu.connected(start, finish) ? res : 1e9;
}

bool solve() {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges) {
        cin >> a >> b >> w;
        a--;
        b--;
    }
    sort(edges.begin(), edges.end());

    int startCost, finishCost;
    cin >> startCost >> finishCost;

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int start, finish;
        cin >> start >> finish;
        start--;
        finish--;

        int res = 1e9;
        for (int from = 0; from < edgeCount; from++)
            res = min(res, getCost(vertexCount, edges, from, start, finish) + startCost + finishCost);

        cout << res << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}