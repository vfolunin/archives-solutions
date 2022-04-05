#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, sz;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        sz.assign(n, 1);
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
        if (sz[ri] < sz[rj]) {
            id[ri] = rj;
            sz[rj] += sz[ri];
        } else {
            id[rj] = ri;
            sz[ri] += sz[rj];
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int recipeCount;
    cin >> recipeCount;

    DSU dsu(5e5 + 1);
    int res = 0;

    for (int i = 0; i < recipeCount; i++) {
        int ingredientCount;
        cin >> ingredientCount;

        set<int> roots;
        for (int j = 0; j < ingredientCount; j++) {
            int ingredient;
            cin >> ingredient;
            roots.insert(dsu.find(ingredient));
        }

        int totalSize = 0;
        for (int root : roots)
            totalSize += dsu.sz[root];

        if (totalSize == ingredientCount) {
            for (int root : roots)
                dsu.merge(*roots.begin(), root);
            res++;
        }
    }

    cout << res;
}