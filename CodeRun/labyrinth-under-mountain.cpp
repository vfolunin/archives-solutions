#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, size;
    int maxSize = 1;

    DSU(int n) {
        size.assign(n, 1);
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
        if (size[ri] < size[rj]) {
            id[ri] = rj;
            size[rj] += size[ri];
        } else {
            id[rj] = ri;
            size[ri] += size[rj];
        }
        maxSize = max({ maxSize, size[ri], size[rj] });
    }
};

struct Edge {
    int a, b, weight;

    bool operator < (const Edge &that) const {
        return weight < that.weight;
    }
};

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, weight] : edges) {
        cin >> a;
        a--;
    }
    for (auto &[a, b, weight] : edges) {
        cin >> b;
        b--;
    }
    for (auto &[a, b, weight] : edges)
        cin >> weight;
    sort(edges.begin(), edges.end());

    DSU dsu(vertexCount);
    vector<int> res(vertexCount, -1);
    res[0] = 0;

    for (auto &[a, b, weight] : edges) {
        dsu.merge(a, b);
        if (res[dsu.maxSize - 1] == -1)
            res[dsu.maxSize - 1] = weight;
    }

    for (int i = (int)res.size() - 2; i >= 0; i--)
        if (res[i] == -1)
            res[i] = res[i + 1];

    for (int value : res)
        cout << value << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}