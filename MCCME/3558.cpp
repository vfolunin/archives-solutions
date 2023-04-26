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

    DSU dsu(1);

    for (string op; cin >> op; ) {
        if (op == "RESET") {
            int n;
            cin >> n;

            dsu = DSU(n);

            cout << "RESET DONE\n";
        } else if (op == "JOIN") {
            int a, b;
            cin >> a >> b;

            if (dsu.connected(a, b))
                cout << "ALREADY " << a << " " << b << "\n";
            else
                dsu.merge(a, b);
        } else {
            int a, b;
            cin >> a >> b;

            cout << (dsu.connected(a, b) ? "YES\n" : "NO\n");
        }
    }
}