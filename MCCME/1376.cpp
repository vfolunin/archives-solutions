#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, weight;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        weight.assign(n, 0);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j, int w) {
        int ri = find(i), rj = find(j);
        if (ri == rj) {
            weight[ri] += w;
            return;
        }
        if (rand() % 2) {
            id[ri] = rj;
            weight[rj] += weight[ri] + w;
        } else {
            id[rj] = ri;
            weight[ri] += weight[rj] + w;
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, opCount;
    cin >> vertexCount >> opCount;

    DSU dsu(vertexCount);

    for (int i = 0; i < opCount; i++) {
        int opType;
        cin >> opType;

        if (opType == 1) {
            int a, b, w;
            cin >> a >> b >> w;
            dsu.merge(a - 1, b - 1, w);
        } else {
            int v;
            cin >> v;
            cout << dsu.weight[dsu.find(v - 1)] << "\n";
        }
    }
}