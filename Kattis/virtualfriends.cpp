#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, sz;

    void add() {
        id.push_back(id.size());
        sz.push_back(1);
    }

    int find(int v) {
        return id[v] == v ? v : id[v] = find(id[v]);
    }

    int merge(int i, int j) {
        int r1 = find(i), r2 = find(j);
        if (r1 == r2)
            return sz[r1];
        if (sz[r1] < sz[r2]) {
            id[r1] = r2;
            sz[r2] += sz[r1];
            return sz[r2];
        } else {
            id[r2] = r1;
            sz[r1] += sz[r2];
            return sz[r1];
        }
    }
};

void solve() {
    int n;
    cin >> n;

    map<string, int> id;
    DSU dsu;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if (!id.count(a)) {
            id[a] = id.size();
            dsu.add();
        }
        if (!id.count(b)) {
            id[b] = id.size();
            dsu.add();
        }

        cout << dsu.merge(id[a], id[b]) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}