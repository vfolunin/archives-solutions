#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;
    int cc;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        cc = n;
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
        cc--;
    }
};

struct Edge {
    int a, b, weight;

    bool operator < (const Edge &that) const {
        return weight < that.weight;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, existingEdgeCount;
    cin >> vertexCount >> edgeCount >> existingEdgeCount;

    vector<Edge> edges(edgeCount);
    int existingEdgesWeight = 0;
    for (int i = 0; i < edgeCount; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].weight;
        edges[i].a--;
        edges[i].b--;
        
        if (i < existingEdgeCount)
            existingEdgesWeight += edges[i].weight;
    }

    DSU dsu(vertexCount);
    sort(edges.begin(), edges.end());
    int mstWeight = 0;

    for (auto &[a, b, weight] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += weight;
        }
    }

    cout << (dsu.cc == 1 && mstWeight <= existingEdgesWeight ? "possible" : "impossible");
}