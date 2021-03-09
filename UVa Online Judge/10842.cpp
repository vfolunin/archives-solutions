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
        return w > that.w;
    }
};

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges)
        cin >> a >> b >> w;

    sort(edges.begin(), edges.end());

    DSU dsu(vertexCount);
    for (auto &[a, b, w] : edges) {
        dsu.merge(a, b);
        if (dsu.cc == 1) {
            cout << "Case #" << test << ": " << w << "\n";
            return;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}