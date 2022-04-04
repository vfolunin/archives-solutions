#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;
    int ccCount;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        ccCount = n;
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
        ccCount--;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

struct Edge {
    int i, b, w;

    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

void solve() {
    int limit, vertexCount;
    cin >> limit >> vertexCount;

    vector<Edge> edges(vertexCount * (vertexCount - 1) / 2);
    for (auto &[a, b, w] : edges)
        cin >> a >> b >> w;

    sort(edges.begin(), edges.end());
    DSU dsu(vertexCount);

    int mstWeight = 0;

    for (auto &[i, b, w] : edges) {
        if (!dsu.connected(i, b)) {
            dsu.merge(i, b);
            mstWeight += w;
        }
    }

    cout << (mstWeight + vertexCount <= limit ? "yes\n" : "no\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}