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
    int a, b;
    double w;

    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

void solve(int test) {
    int ccLimit;
    cin >> ccLimit;

    vector<pair<int, int>> points;
    while (1) {
        int x, y;
        cin >> x;
        if (x == -1)
            break;
        cin >> y;
        points.push_back({ x, y });
    }

    vector<Edge> edges;
    for (int i = 0; i < points.size(); i++)
        for (int j = i + 1; j < points.size(); j++)
            edges.push_back({ i, j, hypot(points[i].first - points[j].first, points[i].second - points[j].second) });

    sort(edges.begin(), edges.end());
    DSU dsu(points.size());

    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            if (dsu.cc == ccLimit) {
                cout << (int)ceil(w) << "\n";
                return;
            }
        }
    }

    cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}