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

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    DSU dsu(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        dsu.merge(a, b);
    }

    cout << dsu.ccCount - 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}