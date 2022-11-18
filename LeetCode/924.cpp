struct DSU {
    vector<int> id, size;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        size.assign(n, 1);
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
        if (size[ri] < size[rj]) {
            id[ri] = rj;
            size[rj] += size[ri];
        } else {
            id[rj] = ri;
            size[ri] += size[rj];
        }
    }
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
        DSU dsu(graph.size() + 1);
        for (int a = 0; a < graph.size(); a++)
            for (int b = 0; b < graph.size(); b++)
                if (graph[a][b])
                    dsu.merge(a, b);
        
        int resSize = 1e9, res = 0;
        for (int curV : initial) {
            DSU curDsu = dsu;
            for (int v : initial)
                if (v != curV)
                    curDsu.merge(v, graph.size());
            
            int curSize = curDsu.size[curDsu.find(graph.size())];
            if (resSize > curSize || resSize == curSize && res > curV) {
                resSize = curSize;
                res = curV;
            }
        }
        
        return res;
    }
};