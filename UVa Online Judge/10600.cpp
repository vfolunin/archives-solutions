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
    int a, b, w;

    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges) {
        cin >> a >> b >> w;
        a--;
        b--;
    }
    sort(edges.begin(), edges.end());

    DSU dsu1(vertexCount);
    int mst1 = 0;
    vector<int> used;

    for (int i = 0; i < edgeCount; i++) {
        if (!dsu1.connected(edges[i].a, edges[i].b)) {
            dsu1.merge(edges[i].a, edges[i].b);
            mst1 += edges[i].w;
            used.push_back(i);
        }
    }

    int mst2 = 1e9;

    for (int i = 0; i < vertexCount - 1; i++) {
        DSU dsu2(vertexCount);
        int curMst2 = 0;
        
        for (int j = 0; j < edgeCount; j++) {
            if (j == used[i])
                continue;
            if (!dsu2.connected(edges[j].a, edges[j].b)) {
                dsu2.merge(edges[j].a, edges[j].b);
                curMst2 += edges[j].w;
            }
        }

        if (dsu2.cc == 1 && curMst2 < mst2)
            mst2 = curMst2;
    }

    cout << mst1 << " " << mst2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}