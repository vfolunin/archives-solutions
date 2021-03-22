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

void solve(int test) {
    int vertexCount, edgeCount, airportCost;
    cin >> vertexCount >> edgeCount >> airportCost;

    vector<Edge> edges;

    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        edges.push_back({ a - 1, b - 1, w });
    }

    sort(edges.begin(), edges.end());
    DSU dsu(vertexCount);
    int resCost = vertexCount * airportCost, resAirports = vertexCount;

    int mstWeight = 0;
    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += w;
        }
        if (resCost > mstWeight + dsu.cc * airportCost) {
            resCost = mstWeight + dsu.cc * airportCost;
            resAirports = dsu.cc;
        }
    }

    cout << "Case #" << test << ": " << resCost << " " << resAirports << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int test = 1; test <= n; test++)
        solve(test);
}