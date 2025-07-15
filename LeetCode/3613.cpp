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
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
        cc--;
    }
};

class Solution {
public:
    int minCost(int vertexCount, vector<vector<int>> &edges, int ccLimit) {
        if (vertexCount <= ccLimit)
            return 0;
            
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        DSU dsu(vertexCount);
        int res = 1e9;
        
        for (vector<int> &edge : edges) {
            dsu.merge(edge[0], edge[1]);
            if (dsu.cc <= ccLimit)
                res = min(res, edge[2]);
        }

        return res;
    }
};