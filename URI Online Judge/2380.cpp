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

    int bankCount, queryCount;
    cin >> bankCount >> queryCount;

    DSU dsu(bankCount);
    for (int i = 0; i < queryCount; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;
        a--;
        b--;

        if (type == 'F')
            dsu.merge(a, b);
        else
            cout << (dsu.connected(a, b) ? "S\n" : "N\n");
    }
}