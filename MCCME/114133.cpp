#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
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

struct Edge {
    int a, b, wNum, wDen;
};

pair<long long, long long> kruskal(int vertexCount, vector<Edge> &edges, double ratio) {
    DSU dsu(vertexCount);
    sort(edges.begin(), edges.end(), [&](Edge &a, Edge &b) {
        return a.wNum - a.wDen * ratio > b.wNum - b.wDen * ratio;
    });
    long long num = 0, den = 0;
    double diff = 0;

    for (auto &[a, b, wNum, wDen] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            num += wNum;
            den += wDen;
            diff += wNum - wDen * ratio;
        }
    }

    if (dsu.cc > 1 || diff < 0)
        return { 0, 0 };

    long long d = gcd(num, den);
    return { num / d, den / d };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, wNum, wDen] : edges)
        cin >> a >> b >> wNum >> wDen;

    double l = 0, r = 1e9;
    for (int i = 0; i < 50; i++) {
        double m = (l + r) / 2;
        auto [num, den] = kruskal(vertexCount, edges, m);
        if (num)
            l = m;
        else
            r = m;
    }

    auto [num, den] = kruskal(vertexCount, edges, l);
    cout << num << "/" << den;
}