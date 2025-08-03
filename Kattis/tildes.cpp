#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, size;

    DSU(int n) {
        for (int v = 0; v < n; v++) {
            id.push_back(v);
            size.push_back(1);
        }
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
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    DSU dsu(size);

    for (int i = 0; i < queryCount; i++) {
        char type;
        cin >> type;

        if (type == 't') {
            int a, b;
            cin >> a >> b;

            dsu.merge(a - 1, b - 1);
        } else {
            int v;
            cin >> v;

            cout << dsu.size[dsu.find(v - 1)] << "\n";
        }
    }
}