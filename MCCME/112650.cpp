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
        if (w != that.w)
            return w < that.w;
        if (a != that.a)
            return a < that.a;
        return b < that.b;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<Edge> edges;
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int w;
            cin >> w;
            if (w)
                edges.push_back({ min(a, b), max(a, b), w });
        }
    }

    sort(edges.begin(), edges.end());
    DSU dsu(vertexCount);

    vector<pair<int, int>> mstEdges;
    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstEdges.push_back({ a, b });
        }
    }

    sort(mstEdges.begin(), mstEdges.end());
    for (auto &[a, b] : mstEdges)
        cout << a + 1 << " " << b + 1 << "\n";
}