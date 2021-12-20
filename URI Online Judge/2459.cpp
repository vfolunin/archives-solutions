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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCountA, edgeCountB;
    cin >> vertexCount >> edgeCountA >> edgeCountB;

    vector<Edge> edges(edgeCountA + edgeCountB);
    for (auto &[a, b, w] : edges) {
        cin >> a >> b >> w;
        a--;
        b--;
    }

    sort(edges.begin(), edges.begin() + edgeCountA);
    sort(edges.begin() + edgeCountA, edges.end());
    DSU dsu(vertexCount);

    int mstWeight = 0;
    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += w;
        }
    }

    cout << mstWeight << "\n";
}