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
    int a, b, weight;

    bool operator < (const Edge &that) const {
        return weight < that.weight;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges) {
        cin >> a >> b >> w;
        a--;
        b--;
    }

    int start, finish;
    cin >> start >> finish;
    start--;
    finish--;

    DSU dsu(vertexCount);
    if (dsu.connected(start, finish)) {
        cout << 0;
        return 0;
    }

    sort(edges.begin(), edges.end());

    for (auto &[a, b, weight] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            if (dsu.connected(start, finish)) {
                cout << weight;
                return 0;
            }
        }
    }
}