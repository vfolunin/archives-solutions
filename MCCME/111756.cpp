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
 
    int vertexCount, edgeCount, queryCount;
    cin >> vertexCount >> edgeCount >> queryCount;

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
    }

    vector<vector<int>> queries(queryCount);
    for (int i = 0; i < queryCount; i++) {
        string queryType;
        int a, b;

        cin >> queryType >> a >> b;
        queries[i] = { queryType == "ask", a - 1, b - 1 };
    }

    DSU dsu(vertexCount);
    vector<int> res;

    for (int i = queryCount - 1; i >= 0; i--) {
        if (queries[i][0])
            res.push_back(dsu.connected(queries[i][1], queries[i][2]));
        else
            dsu.merge(queries[i][1], queries[i][2]);
    }

    reverse(res.begin(), res.end());
    for (int value : res)
        cout << (value ? "YES\n" : "NO\n");
}