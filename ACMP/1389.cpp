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

    int height, width;
    cin >> height >> width;

    DSU dsu(height * width);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int type;
            cin >> type;

            if (type == 1 || type == 3)
                dsu.merge(y * width + x, (y + 1) * width + x);
            if (type == 2 || type == 3)
                dsu.merge(y * width + x, y * width + x + 1);
        }
    }

    int cost = 0;
    vector<pair<int, int>> edges;

    for (int y = 0; y < height - 1; y++) {
        for (int x = 0; x < width; x++) {
            if (!dsu.connected(y * width + x, (y + 1) * width + x)) {
                dsu.merge(y * width + x, (y + 1) * width + x);
                cost++;
                edges.push_back({ y * width + x, 1 });
            }
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width - 1; x++) {
            if (!dsu.connected(y * width + x, y * width + x + 1)) {
                dsu.merge(y * width + x, y * width + x + 1);
                cost += 2;
                edges.push_back({ y * width + x, 2 });
            }
        }
    }

    cout << edges.size() << " " << cost << "\n";
    for (auto &[v, type] : edges)
        cout << v / width + 1 << " " << v % width + 1 << " " << type << "\n";
}