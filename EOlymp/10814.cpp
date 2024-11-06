#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, size, minValue, maxValue;

    DSU(int n) {
        for (int v = 0; v < n; v++) {
            id.push_back(v);
            size.push_back(1);
            minValue.push_back(v + 1);
            maxValue.push_back(v + 1);
        }
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;

        if (size[ri] < size[rj]) {
            id[ri] = rj;
            size[rj] += size[ri];
            minValue[rj] = min(minValue[rj], minValue[ri]);
            maxValue[rj] = max(maxValue[rj], maxValue[ri]);
        } else {
            id[rj] = ri;
            size[ri] += size[rj];
            minValue[ri] = min(minValue[ri], minValue[rj]);
            maxValue[ri] = max(maxValue[ri], maxValue[rj]);
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, queryCount;
    cin >> vertexCount >> queryCount;

    DSU dsu(vertexCount);

    for (int i = 0; i < queryCount; i++) {
        string type;
        cin >> type;

        if (type == "get") {
            int i;
            cin >> i;

            i = dsu.find(i - 1);
            
            cout << dsu.minValue[i] << " " << dsu.maxValue[i] << " " << dsu.size[i] << "\n";
        } else {
            int i, j;
            cin >> i >> j;

            dsu.merge(i - 1, j - 1);
        }
    }
}