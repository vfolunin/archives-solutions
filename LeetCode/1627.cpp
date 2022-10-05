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

class Solution {
public:
    vector<bool> areConnected(int vertexCount, int threshold, vector<vector<int>> &queries) {
        DSU dsu(vertexCount + 1);
        
        for (int a = threshold + 1; a <= vertexCount; a++)
            for (int b = a * 2; b <= vertexCount; b += a)
                dsu.merge(a, b);
        
        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
            res[i] = dsu.connected(queries[i][0], queries[i][1]);
        return res;
    }
};