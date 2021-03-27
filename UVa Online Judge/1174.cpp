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
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges;
    map<string, int> vertexId;
    for (int i = 0; i < edgeCount; i++) {
        string sa, sb;
        int w;
        cin >> sa >> sb >> w;

        if (!vertexId.count(sa))
            vertexId[sa] = vertexId.size();
        if (!vertexId.count(sb))
            vertexId[sb] = vertexId.size();

        edges.push_back({ vertexId[sa], vertexId[sb], w });
    }

    sort(edges.begin(), edges.end());

    DSU dsu(vertexCount);

    int mst = 0;
    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mst += w;
        }
    }

    if (test)
        cout << "\n";
    cout << mst << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}