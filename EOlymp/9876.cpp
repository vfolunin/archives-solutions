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
        for (int v = 0; v < n; v++)
            id.push_back(v);
        ccCount = n;
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
        ccCount--;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

struct Edge {
    int a, b, w;

    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

int hammingDistance(string &a, string &b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] != b[i];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, wordSize;
    cin >> vertexCount >> wordSize;

    vector<string> words(vertexCount);
    for (string &word : words)
        cin >> word;

    vector<Edge> edges;
    for (int a = 0; a < vertexCount; a++)
        for (int b = a + 1; b < vertexCount; b++)
            edges.push_back({ a, b, hammingDistance(words[a], words[b]) });

    sort(edges.begin(), edges.end());
    DSU dsu(vertexCount);

    double mstWeight = 0;
    vector<pair<int, int>> mst;

    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += w;
            mst.push_back({ a, b });
        }
    }

    cout << mstWeight << "\n";
    for (auto &[a, b] : mst)
        cout << a << " " << b << "\n";
}