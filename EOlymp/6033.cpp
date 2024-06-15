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
    int vertexCount;
    cin >> vertexCount;
    vertexCount += 2;

    vector<int> x(vertexCount), y(vertexCount);
    for (int i = 0; i < vertexCount; i++)
        cin >> x[i] >> y[i];
    
    DSU dsu(vertexCount);
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            if (abs(x[a] - x[b]) + abs(y[a] - y[b]) <= 1000)
                dsu.merge(a, b);

    cout << (dsu.connected(0, vertexCount - 1) ? "happy\n" : "sad\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}