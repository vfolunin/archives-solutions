struct DSU {
    vector<int> id, andSum;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        andSum.assign(n, -1);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j, int value) {
        int ri = find(i), rj = find(j);
        if (rand() % 2) {
            id[ri] = rj;
            andSum[rj] &= andSum[ri] & value;
        } else {
            id[rj] = ri;
            andSum[ri] &= andSum[rj] & value;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int vertexCount, vector<vector<int>> &edges, vector<vector<int>> &queries) {
        DSU dsu(vertexCount);
        for (vector<int> &edge : edges)
            dsu.merge(edge[0], edge[1], edge[2]);
        
        vector<int> res(queries.size(), -1);
        for (int i = 0; i < queries.size(); i++)
            if (dsu.connected(queries[i][0], queries[i][1]))
                res[i] = dsu.andSum[dsu.find(queries[i][0])];
        return res;
    }
};