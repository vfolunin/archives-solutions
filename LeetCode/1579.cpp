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
    int maxNumEdgesToRemove(int vertexCount, vector<vector<int>> &allEdges) {
        vector<vector<pair<int, int>>> edges(3);
        for (vector<int> &edge : allEdges)
            edges[edge[0] - 1].push_back({ edge[1] - 1, edge[2] - 1 });
        
        int res = 0;
        DSU dsuA(vertexCount);
        
        for (auto &[a, b] : edges[2]) {
            if (!dsuA.connected(a, b))
                dsuA.merge(a, b);
            else
                res++;
        }
        
        DSU dsuB = dsuA;
        
        for (auto &[a, b] : edges[0]) {
            if (!dsuA.connected(a, b))
                dsuA.merge(a, b);
            else
                res++;
        }
        
        for (auto &[a, b] : edges[1]) {
            if (!dsuB.connected(a, b))
                dsuB.merge(a, b);
            else
                res++;
        }
        
        if (dsuA.cc == 1 && dsuB.cc == 1)
            return res;
        else
            return -1;
    }
};