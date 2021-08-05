#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, ccSize;
    int ccCount, maxCcSize;

    DSU(int n) {
        for (int v = 0; v < n; v++) {
            id.push_back(v);
            ccSize.push_back(1);
        }
        ccCount = n;
        maxCcSize = 1;
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        ccCount--;
        if (rand() % 2) {
            id[ri] = rj;
            ccSize[rj] += ccSize[ri];
            maxCcSize = max(maxCcSize, ccSize[rj]);
        } else {
            id[rj] = ri;
            ccSize[ri] += ccSize[rj];
            maxCcSize = max(maxCcSize, ccSize[ri]);
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    DSU dsu(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        dsu.merge(a - 1, b - 1);
        cout << dsu.ccCount << " " << dsu.maxCcSize << "\n";
    }
}