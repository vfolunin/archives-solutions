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

class Solution {
public:
    int minimumCost(int vertexCount, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        DSU dsu(vertexCount);
        int mstWeight = 0;

        for (vector<int> &edge : edges) {
            if (!dsu.connected(edge[0] - 1, edge[1] - 1)) {
                dsu.merge(edge[0] - 1, edge[1] - 1);
                mstWeight += edge[2];
            }
        }

        return dsu.cc == 1 ? mstWeight : -1;
    }
};