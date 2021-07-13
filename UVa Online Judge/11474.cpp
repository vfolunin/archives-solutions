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

void solve() {
    int treeCount, doctorCount, treeDist, doctorDist;
    cin >> treeCount >> doctorCount >> treeDist >> doctorDist;

    vector<pair<int, int>> doctorCoord(doctorCount);
    for (auto &[x, y] : doctorCoord)
        cin >> x >> y;

    vector<vector<pair<int, int>>> treeCoord(treeCount);
    for (auto &coord : treeCoord) {
        int branchCount;
        cin >> branchCount;
        coord.resize(branchCount);
        for (auto &[x, y] : coord)
            cin >> x >> y;
    }

    DSU dsu(treeCount + doctorCount);
    for (int i = 0; i < treeCount; i++) {
        for (auto &[xi, yi] : treeCoord[i]) {
            for (int j = i + 1; j < treeCount; j++) {
                for (auto &[xj, yj] : treeCoord[j])
                    if ((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj) <= treeDist * treeDist)
                        dsu.merge(i, j);
            }

            for (int j = 0; j < doctorCount; j++) {
                auto &[xj, yj] = doctorCoord[j];
                if ((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj) <= doctorDist * doctorDist)
                    dsu.merge(i, treeCount + j);
            }
        }
    }

    for (int i = 0; i < doctorCount; i++) {
        if (dsu.connected(0, treeCount + i)) {
            cout << "Tree can be saved :)\n";
            return;
        }
    }
    cout << "Tree can't be saved :(\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}