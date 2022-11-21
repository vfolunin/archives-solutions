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
        vector<int> inInitial(graph.size());
        for (int v : initial)
            inInitial[v] = 1;
        
        DSU dsu(graph.size() + 1);
        for (int a = 0; a < graph.size(); a++)
            for (int b = 0; b < graph.size(); b++)
                if (!inInitial[a] && !inInitial[b] && graph[a][b])
                    dsu.merge(a, b);
        
        unordered_map<int, unordered_set<int>> goodNeighbors;
        unordered_map<int, int> badNeighborCount;
        for (int a : initial) {
            for (int b = 0; b < graph.size(); b++)
                if (!inInitial[b] && graph[a][b])
                    goodNeighbors[a].insert(dsu.find(b));
            
            for (int goodNeighbor : goodNeighbors[a])
                badNeighborCount[goodNeighbor]++;
        }
        
        int resSize = -1, res;
        for (int v : initial) {
            int size = 0;
            for (int goodNeighbor : goodNeighbors[v])
                if (badNeighborCount[goodNeighbor] == 1)
                    size += dsu.size[goodNeighbor];
            
            if (resSize < size || resSize == size && res > v) {
                resSize = size;
                res = v;
            }
        }
        
        return res;
    }
};