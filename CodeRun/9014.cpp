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

int getDist(vector<int> &a, vector<int> &b) {
    int res = 1e9;
    for (int i = 0; i < 3; i++)
        res = min(res, abs(a[i] - b[i]));
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> coords(vertexCount, vector<int>(4));
    for (int i = 0; i < coords.size(); i++) {
        cin >> coords[i][0] >> coords[i][1] >> coords[i][2];
        coords[i][3] = i;
    }

    vector<Edge> edges;
    for (int j = 0; j < 3; j++) {
        sort(coords.begin(), coords.end(), [&](vector<int> &l, vector<int> &r) {
            return l[j] < r[j];
        });
        for (int i = 0; i + 1 < coords.size(); i++)
            edges.push_back({ coords[i][3], coords[i + 1][3], getDist(coords[i], coords[i + 1]) });
    }

    DSU dsu(vertexCount);
    sort(edges.begin(), edges.end());
    long long mstWeight = 0;

    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += w;
        }
    }

    cout << mstWeight;
}