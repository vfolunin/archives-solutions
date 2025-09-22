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

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    map<string, int> vertexId;
    for (int i = 0; i < vertexCount; i++) {
        string name;
        cin >> name;
        vertexId[name] = i;
    }

    vector<Edge> edges;

    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        int w;
        cin >> a >> b >> w;

        edges.push_back({ vertexId[a], vertexId[b], w });
    }

    string name;
    cin >> name;

    sort(edges.begin(), edges.end());
    DSU dsu(vertexCount);
    int mstWeight = 0;

    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += w;
        }
    }

    if (dsu.cc == 1)
        cout << mstWeight << "\n";
    else
        cout << "Impossible\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}