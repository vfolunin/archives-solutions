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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    DSU dsu(2 * vertexCount);

    while (1) {
        int type, a, b;
        cin >> type >> a >> b;

        if (!type)
            break;

        if (type == 1) {
            if (dsu.connected(2 * a, 2 * b + 1)) {
                cout << "-1\n";
            } else {
                dsu.merge(2 * a, 2 * b);
                dsu.merge(2 * a + 1, 2 * b + 1);
            }
        } else if (type == 2) {
            if (dsu.connected(2 * a, 2 * b)) {
                cout << "-1\n";
            } else {
                dsu.merge(2 * a, 2 * b + 1);
                dsu.merge(2 * a + 1, 2 * b);
            }
        } else if (type == 3) {
            cout << (dsu.connected(2 * a, 2 * b) ? "1\n" : "0\n");
        } else if (type == 4) {
            cout << (dsu.connected(2 * a, 2 * b + 1) ? "1\n" : "0\n");
        }
    }
}