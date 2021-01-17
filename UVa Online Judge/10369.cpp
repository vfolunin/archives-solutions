#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;
    int ccCount;

    DSU(int n) {
        for (int i = 0; i < n; i++)
            id.push_back(i);
        ccCount = n;
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    void merge(int i, int j) {
        int r1 = find(i), r2 = find(j);
        if (r1 == r2)
            return;
        ccCount--;
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

void solve() {
    int ccCount, vertexCount;
    cin >> ccCount >> vertexCount;

    vector<int> x(vertexCount), y(vertexCount);
    for (int i = 0; i < vertexCount; i++)
        cin >> x[i] >> y[i];

    vector<Edge> edges;
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            edges.push_back({ a, b, (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]) });
    sort(edges.begin(), edges.end());

    DSU dsu(vertexCount);
    int res = 0;

    for (int i = 0; i < edges.size() && dsu.ccCount > ccCount; i++) {
        dsu.merge(edges[i].a, edges[i].b);
        res = edges[i].w;
    }

    cout.precision(2);
    cout << fixed << sqrt(res) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}