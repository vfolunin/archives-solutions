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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, opCount;
    cin >> vertexCount >> opCount;

    DSU dsu(vertexCount);

    for (int i = 0; i < opCount; i++) {
        char op;
        int a, b;
        cin >> op >> a >> b;

        if (op == '=')
            dsu.merge(a, b);
        else
            cout << (dsu.connected(a, b) ? "yes\n" : "no\n");
    }
}