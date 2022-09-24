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
    vector<bool> distanceLimitedPathsExist(int vertexCount, vector<vector<int>> &edges, vector<vector<int>> &queries) {
        vector<int> queryOrder(queries.size());
        iota(queryOrder.begin(), queryOrder.end(), 0);
        sort(queryOrder.begin(), queryOrder.end(), [&](int a, int b) {
            return queries[a][2] < queries[b][2];
        });
        
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });
        
        DSU dsu(vertexCount);
        vector<bool> res(queries.size());
        
        int ei = 0;
        for (int qi : queryOrder) {
            while (ei < edges.size() && edges[ei][2] < queries[qi][2]) {
                dsu.merge(edges[ei][0], edges[ei][1]);
                ei++;
            }
            res[qi] = dsu.connected(queries[qi][0], queries[qi][1]);
        }
        
        return res;
    }
};