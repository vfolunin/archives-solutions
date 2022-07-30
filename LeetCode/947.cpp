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
    int removeStones(vector<vector<int>> &stones) {
        DSU dsu(stones.size());
        
        for (int i = 0; i < stones.size(); i++)
            for (int j = i + 1; j < stones.size(); j++)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    dsu.merge(i, j);
        
        return stones.size() - dsu.cc;
    }
};