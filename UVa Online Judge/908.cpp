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
        for (int i = 0; i < n; i++)
            id.push_back(i);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int r1 = find(i), r2 = find(j);
        if (r1 == r2)
            return;
        if (rand() % 2)
            id[r1] = r2;
        else
            id[r2] = r1;
    }
};

struct Edge {
    int a, b, w;

    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

istream &operator >> (istream &in, Edge &edge) {
    in >> edge.a >> edge.b >> edge.w;
    edge.a--;
    edge.b--;
    return in;
}

bool solve(int test) {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;
    
    long long initialCost = 0;
    for (int i = 0; i < vertexCount - 1; i++) {
        Edge edge;
        cin >> edge;
        initialCost += edge.w;
    }

    vector<Edge> edges;

    int newEdgeCount;
    cin >> newEdgeCount;

    for (int i = 0; i < newEdgeCount; i++) {
        edges.emplace_back();
        cin >> edges.back();
    }

    int edgeCount;
    cin >> edgeCount;

    for (int i = 0; i < edgeCount; i++) {
        edges.emplace_back();
        cin >> edges.back();
    }

    sort(edges.begin(), edges.end());

    DSU dsu(vertexCount);
    long long newCost = 0;
    for (auto [a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            newCost += w;
        }
    }

    if (test)
        cout << "\n";
    cout << initialCost << "\n" << newCost << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}