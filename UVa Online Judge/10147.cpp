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
    int vertexCount;
    cin >> vertexCount;

    vector<int> x(vertexCount), y(vertexCount);
    for (int i = 0; i < vertexCount; i++)
        cin >> x[i] >> y[i];

    vector<Edge> edges;
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            edges.push_back({ i, j, dx * dx + dy * dy });
        }
    }

    sort(edges.begin(), edges.end());
    DSU dsu(vertexCount);

    int edgeCount;
    cin >> edgeCount;

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        dsu.merge(a - 1, b - 1);
    }

    vector<pair<int, int>> res;
    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            res.push_back({ a, b });
        }
    }

    if (test)
        cout << "\n";
    if (res.empty())
        cout << "No new highways need\n";
    else
        for (auto &[a, b] : res)
            cout << a + 1 << " " << b + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}