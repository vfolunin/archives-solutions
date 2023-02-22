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
    int getCost(DSU &dsu, int zeroPos) {
        int res = 0;
        for (int i = 0; i < dsu.id.size(); i++)
            if (dsu.id[i] == i && dsu.size[i] > 1)
                res += dsu.size[i] + (dsu.find(zeroPos) == i ? -1 : 1);
        return res;
    }

public:
    int sortArray(vector<int> &a) {
        DSU dsuL(a.size());
        for (int i = 0; i < a.size(); i++)
            dsuL.merge(i, a[i]);
        
        DSU dsuR(a.size());
        for (int i = 0; i < a.size(); i++)
            dsuR.merge(i, a[i] ? a[i] - 1 : a.size() - 1);
        
        return min(getCost(dsuL, 0), getCost(dsuR, a.size() - 1));
    }
};