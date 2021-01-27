#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, sz;

    DSU(int n) {
        for (int v = 0; v < n; v++) {
            id.push_back(v);
            sz.push_back(1);
        }
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
        if (sz[ri] < sz[rj]) {
            id[ri] = rj;
            sz[rj] += sz[ri];
        } else {
            id[rj] = ri;
            sz[ri] += sz[rj];
        }
    }

    int trees() {
        int res = 0;
        for (int i = 0; i < id.size(); i++)
            res += id[i] == i && sz[i] > 1;
        return res;
    }

    int acorns() {
        int res = 0;
        for (int i = 0; i < id.size(); i++)
            res += id[i] == i && sz[i] == 1;
        return res;
    }
};

void solve() {
    map<char, int> vertexId;
    vector<pair<int, int>> edges;

    while (1) {
        string line;
        cin >> line;

        if (line[0] == '*')
            break;

        if (!vertexId.count(line[1]))
            vertexId[line[1]] = vertexId.size();
        if (!vertexId.count(line[3]))
            vertexId[line[3]] = vertexId.size();
        edges.push_back({ vertexId[line[1]], vertexId[line[3]] });
    }

    string line;
    cin >> line;
    
    for (int i = 0; i < line.size(); i += 2)
        if (!vertexId.count(line[i]))
            vertexId[line[i]] = vertexId.size();

    DSU dsu(vertexId.size());
    for (auto &[a, b] : edges)
        dsu.merge(a, b);

    cout << "There are " << dsu.trees() << " tree(s) and " << dsu.acorns() << " acorn(s).\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}