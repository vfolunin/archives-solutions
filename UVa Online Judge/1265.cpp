#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;
    vector<int> size;

    DSU(int n) {
        for (int v = 0; v < n; v++) {
            id.push_back(v);
            size.push_back(1);
        }
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
        if (rand() % 2) {
            id[ri] = rj;
            size[rj] += size[ri];
        } else {
            id[rj] = ri;
            size[ri] += size[rj];
        }
    }
};

struct Edge {
    int a, b, w;

    bool operator < (const Edge &that) const {
        return w > that.w;
    }
};

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> outerDist(vertexCount, vector<int>(vertexCount));
    vector<vector<int>> innerDist(vertexCount, vector<int>(vertexCount, 1e9));
    vector<Edge> edges(edgeCount);

    for (auto &[a, b, w] : edges) {
        cin >> a >> b >> w;
        a--;
        b--;
        outerDist[a][b] = outerDist[b][a] = w;
        innerDist[a][b] = innerDist[b][a] = w;
    }

    sort(edges.begin(), edges.end());
    DSU dsu(vertexCount);

    int res = 0;
    for (auto &[a, b, w] : edges) {
        int ra = dsu.find(a), rb = dsu.find(b);
        if (ra == rb)
            continue;

        dsu.merge(ra, rb);
        int rc = dsu.find(ra);

        int outer = 0, inner = w;
        for (int v = 0; v < vertexCount; v++) {
            outerDist[rc][v] = outerDist[v][rc] = max(outerDist[ra][v], outerDist[rb][v]);
            innerDist[rc][v] = innerDist[v][rc] = min(innerDist[ra][v], innerDist[rb][v]);
            if (dsu.find(v) != rc)
                outer = max(outer, outerDist[rc][v]);
            else
                inner = min(inner, innerDist[rc][v]);
        }

        if (inner > outer)
            res += dsu.size[rc];
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}