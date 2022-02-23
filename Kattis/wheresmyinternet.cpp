#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;
    int ccCount;

    DSU(int n) {
        for (int i = 0; i < n; i++)
            id.push_back(i);
        ccCount = n;
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int r1 = find(i), r2 = find(j);
        if (r1 == r2)
            return;
        ccCount--;
        if (rand() % 2)
            id[r1] = r2;
        else
            id[r2] = r1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    DSU dsu(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        dsu.merge(a - 1, b - 1);
    }

    if (dsu.ccCount == 1) {
        cout << "Connected";
    } else {
        for (int v = 0; v < vertexCount; v++)
            if (!dsu.connected(0, v))
                cout << v + 1 << "\n";
    }
}