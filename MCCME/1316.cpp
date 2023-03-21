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
    bool inMst = 0, forbidden = 0;

    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

long long getMstWeight(vector<Edge> &edges, int vertexCount, bool mark) {
    DSU dsu(vertexCount);
    long long mstWeight = 0;
    for (auto &[a, b, w, inMst, forbidden] : edges) {
        if (!forbidden && !dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += w;
            if (mark)
                inMst = 1;
        }
    }
    return dsu.cc == 1 ? mstWeight : 1e18;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w, inMst, forbidden] : edges) {
        cin >> a >> b >> w;
        a--;
        b--;
    }

    sort(edges.begin(), edges.end());
    long long mstWeight1 = getMstWeight(edges, vertexCount, 1), mstWeight2 = 1e18;

    for (auto &[a, b, w, inMst, forbidden] : edges) {
        if (!inMst)
            continue;
        forbidden = 1;
        mstWeight2 = min(mstWeight2, getMstWeight(edges, vertexCount, 0));
        forbidden = 0;
    }

    cout << mstWeight1 << " " << mstWeight2;
}