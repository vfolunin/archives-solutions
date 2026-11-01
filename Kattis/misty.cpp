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
    int a, b, weight, index;

    bool operator < (const Edge &that) const {
        return weight < that.weight;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (int i = 0; i < edges.size(); i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].weight;
        edges[i].a--;
        edges[i].b--;
        edges[i].index = i;
    }

    DSU dsu(vertexCount);
    sort(edges.begin(), edges.end());
    vector<int> indexes;

    for (auto &[a, b, weight, index] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            indexes.push_back(index);
        }
    }

    cout << indexes.size() << "\n";
    for (int index : indexes)
        cout << index + 1 << "\n";
}