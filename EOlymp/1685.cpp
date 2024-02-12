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
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
        cc--;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<int> x(pointCount), y(pointCount);
    DSU dsu(pointCount);

    for (int i = 0; i < pointCount; i++) {
        cin >> x[i] >> y[i];

        for (int j = 0; j < i; j++) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            if (dx * dx + dy * dy < 4)
                dsu.merge(i, j);
        }
    }

    cout << dsu.cc;
}