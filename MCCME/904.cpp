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
    int a, b, w, i;

    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (int i = 0; i < edges.size(); i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        edges[i].a--;
        edges[i].b--;
        edges[i].i = i;
    }

    sort(edges.begin(), edges.end());
    DSU dsu(vertexCount);
    vector<int> mstEdges;

    for (int ei = 0; ei < edges.size(); ei++) {
        auto &[a, b, w, i] = edges[ei];
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstEdges.push_back(ei);
        }
    }

    if (dsu.cc > 1) {
        cout << "Impossible";
        return 0;
    }

    int costA, countA, typeA = 5, costB, countB, typeB = 6;
    cin >> costA >> countA >> costB >> countB;
    if (costA > costB) {
        swap(costA, costB);
        swap(countA, countB);
        swap(typeA, typeB);
    }

    vector<vector<int>> can(mstEdges.size() + 1, vector<int>(countA + 1));
    can[0][0] = 1;
    for (int i = 1; i <= mstEdges.size(); i++) {
        can[i] = can[i - 1];
        for (int w = edges[mstEdges[i - 1]].w; w <= countA; w++)
            can[i][w] |= can[i - 1][w - edges[mstEdges[i - 1]].w];
    }

    while (!can[mstEdges.size()][countA])
        countA--;

    set<int> aEdges;
    for (int i = mstEdges.size(), w = countA; i; i--) {
        if (!can[i - 1][w]) {
            aEdges.insert(mstEdges[i - 1]);
            w -= edges[mstEdges[i - 1]].w;
        }
    }

    long long resCost = 0, needA = 0, needB = 0;
    vector<pair<int, int>> res;

    for (int ei : mstEdges) {
        if (aEdges.count(ei)) {
            needA += edges[ei].w;
            resCost += costA * edges[ei].w;
            res.push_back({ ei, typeA });
        } else {
            needB += edges[ei].w;
            resCost += costB * edges[ei].w;
            res.push_back({ ei, typeB });
        }
    }

    if (needA > countA || needB > countB) {
        cout << "Impossible";
    } else {
        cout << resCost << "\n";
        for (auto &[ei, type] : res)
            cout << edges[ei].i + 1 << " " << type << "\n";
    }
}