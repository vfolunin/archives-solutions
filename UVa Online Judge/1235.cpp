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

int dist(const string &a, const string &b) {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        int d = abs(a[i] - b[i]);
        res += min(d, 10 - d);
    }
    return res;
}

void solve() {
    int vertexCount;
    cin >> vertexCount;

    vector<string> keys(vertexCount);
    for (string &key : keys) {
        cin >> key;
        key = string(4 - key.size(), '0') + key;
    }

    vector<Edge> edges;
    for (int a = 0; a < keys.size(); a++)
        for (int b = a + 1; b < keys.size(); b++)
            edges.push_back({ a, b, dist(keys[a], keys[b]) });

    sort(edges.begin(), edges.end());
    DSU dsu(keys.size());

    int mstWeight = 0;
    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += w;
        }
    }

    int addWeight = 1e9;
    for (string &key : keys)
        addWeight = min(addWeight, dist("0000", key));
    mstWeight += addWeight;

    cout << mstWeight << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}