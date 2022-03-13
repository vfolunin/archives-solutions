#include <iostream>
#include <algorithm>
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
    int a, b, w;

    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges) {
        cin >> a >> b >> w;
        if (a > b)
            swap(a, b);
    }

    sort(edges.begin(), edges.end());
    DSU dsu(vertexCount);

    int mstWeight = 0;
    vector<pair<int, int>> mst;

    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += w;
            mst.push_back({ a, b });
        }
    }

    sort(mst.begin(), mst.end());

    if (dsu.ccCount > 1) {
        cout << "Impossible\n";
    } else {
        cout << mstWeight << "\n";
        for (auto &[a, b] : mst)
            cout << a << " " << b << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}