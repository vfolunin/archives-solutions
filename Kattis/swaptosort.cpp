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
        for (int i = 0; i < n; i++)
            id.push_back(i);
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
        if (rand() % 2)
            id[r1] = r2;
        else
            id[r2] = r1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, swapCount;
    cin >> size >> swapCount;

    DSU dsu(size);

    for (int i = 0; i < swapCount; i++) {
        int a, b;
        cin >> a >> b;
        dsu.merge(a - 1, b - 1);
    }

    for (int l = 0, r = size - 1; l < r; l++, r--) {
        if (!dsu.connected(l, r)) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}