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

bool solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    DSU dsu(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        dsu.merge(a - 1, b - 1);
    }

    cout << "Case " << test << ": " << dsu.cc << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}