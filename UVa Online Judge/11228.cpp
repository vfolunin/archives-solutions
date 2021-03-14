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
    int a, b;
    double w;

    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

void solve(int test) {
    int vertexCount;
    double threshold;
    cin >> vertexCount >> threshold;

    vector<double> x(vertexCount), y(vertexCount);
    for (int i = 0; i < vertexCount; i++)
        cin >> x[i] >> y[i];

    vector<Edge> edges;
    for (int i = 0; i < vertexCount; i++)
        for (int j = i + 1; j < vertexCount; j++)
            edges.push_back({ i, j, hypot(x[i] - x[j], y[i] - y[j]) });

    sort(edges.begin(), edges.end());

    DSU dsu(vertexCount);
    int cc = vertexCount;
    double sum1 = 0, sum2 = 0;

    for (auto &[a, b, w] : edges) {
        if (dsu.connected(a, b))
            continue;

        if (w <= threshold + 1e-9) {
            cc--;
            sum1 += w;
        } else {
            sum2 += w;
        }
        dsu.merge(a, b);
    }

    cout.precision(0);
    cout << "Case #" << test << ": " << cc << " " << fixed << sum1 << " " << sum2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}