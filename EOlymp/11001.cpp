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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges) {
        cin >> a >> b >> w;
        a--;
        b--;
    }

    DSU dsu(vertexCount);
    sort(edges.begin(), edges.end());
    long long mstWeight = 0;

    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += w;
        }
    }

    if (dsu.ccCount == 1)
        cout << mstWeight;
    else
        cout << "IMPOSSIBLE";
}