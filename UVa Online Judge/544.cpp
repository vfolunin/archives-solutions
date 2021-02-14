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
        return w > that.w;
    }
};

bool solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    map<string, int> vertexId;
    vector<Edge> edges;

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

    string sa, sb;
    cin >> sa >> sb;
    int va = vertexId[sa], vb = vertexId[sb];

    sort(edges.begin(), edges.end());
    DSU dsu(vertexCount);

    cout << "Scenario #" << test << "\n";
    for (auto &[a, b, w] : edges) {
        dsu.merge(a, b);
        if (dsu.connected(va, vb)) {
            cout << w << " tons\n\n";
            break;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}