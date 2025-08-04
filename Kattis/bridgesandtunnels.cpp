#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, size;

    void add() {
        id.push_back(id.size());
        size.push_back(1);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    int merge(int i, int j) {
        if (i >= id.size())
            add();
        if (j >= id.size())
            add();
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return size[ri];
        if (size[ri] < size[rj]) {
            id[ri] = rj;
            return size[rj] += size[ri];
        } else {
            id[rj] = ri;
            return size[ri] += size[rj];
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    DSU dsu;
    unordered_map<string, int> id;

    for (int i = 0; i < queryCount; i++) {
        string a, b;
        cin >> a >> b;

        if (!id.count(a))
            id[a] = id.size();
        if (!id.count(b))
            id[b] = id.size();

        cout << dsu.merge(id[a], id[b]) << "\n";
    }
}