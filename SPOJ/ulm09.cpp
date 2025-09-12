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

    int find(int v) {
        return id[v] == v ? v : id[v] = find(id[v]);
    }

    bool connected(int v1, int v2) {
        return find(v1) == find(v2);
    }

    void merge(int v1, int v2) {
        int r1 = find(v1), r2 = find(v2);
        if (r1 == r2)
            return;
        if (rand() % 2)
            id[r1] = r2;
        else
            id[r2] = r1;
    }
};

struct Edge {
    int a, b, weight;

    bool operator < (const Edge &that) const {
        return weight < that.weight;
    }
};

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, weight] : edges)
        cin >> a >> b >> weight;

    int res = 0;

    sort(edges.begin(), edges.end());

    DSU dsu(vertexCount);
    for (auto &[a, b, weight] : edges) {
        if (!dsu.connected(a, b))
            dsu.merge(a, b);
        else
            res += weight;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}