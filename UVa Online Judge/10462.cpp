#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;
    int cc;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        cc = n;
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
        cc--;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

struct Edge {
    int a, b, w, marked = 0, prohibited = 0;

    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

int mst(int vertexCount, vector<Edge> &edges, bool mark) {
    DSU dsu(vertexCount);
    int mstWeight = 0;

    for (auto &[a, b, w, marked, prohibited] : edges) {
        if (prohibited)
            continue;
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += w;
            if (mark)
                marked = 1;
        }
    }

    return dsu.cc == 1 ? mstWeight : -1;
}

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w, marked, prohibited] : edges) {
        cin >> a >> b >> w;
        a--;
        b--;
    }

    sort(edges.begin(), edges.end());
    int mstWeight = mst(vertexCount, edges, 1);

    cout << "Case #" << test << " : ";
    if (mstWeight == -1) {
        cout << "No way\n";
        return;
    }

    int secondMstWeight = 1e9;
    for (auto &[a, b, w, marked, prohibited] : edges) {
        if (marked) {
            prohibited = 1;
            int curMstWeight = mst(vertexCount, edges, 0);
            if (curMstWeight != -1 && secondMstWeight > curMstWeight)
                secondMstWeight = curMstWeight;
            prohibited = 0;
        }
    }

    if (secondMstWeight == 1e9)
        cout << "No second way\n";
    else
        cout << secondMstWeight << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}