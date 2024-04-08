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
        cc--;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

struct Edge {
    int a, b, weight;

    bool operator < (const Edge &that) const {
        return weight < that.weight;
    }
};

void solve() {
    int vertexCount, edgeCount, weight1, weight2;
    cin >> vertexCount >> edgeCount >> weight1 >> weight2;
    vertexCount++;

    vector<Edge> edges(edgeCount);
    for (int v = 1; v < vertexCount; v++)
        edges.push_back({ 0, v, weight1 });

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        edges.push_back({ a, b, weight2 });
    }

    sort(edges.begin(), edges.end());
    DSU dsu(vertexCount);
    long long mstWeight = 0;

    for (auto &[a, b, weight] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += weight;
        }
    }

    cout << mstWeight << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}