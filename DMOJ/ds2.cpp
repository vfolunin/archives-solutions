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
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
        cc--;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<pair<int, int>> edges(edgeCount);
    for (auto &[a, b] : edges) {
        cin >> a >> b;
        a--;
        b--;
    }

    DSU dsu(vertexCount);
    vector<int> res;

    for (int i = 0; i < edges.size(); i++) {
        if (!dsu.connected(edges[i].first, edges[i].second)) {
            dsu.merge(edges[i].first, edges[i].second);
            res.push_back(i);
        }
    }

    if (dsu.cc > 1) {
        cout << "Disconnected Graph";
    } else {
        for (int i : res)
            cout << i + 1 << "\n";
    }
}