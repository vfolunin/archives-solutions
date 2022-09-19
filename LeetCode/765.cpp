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
    int minSwapsCouples(vector<int> &a) {
        DSU dsu(a.size() / 2);
        for (int i = 0; i < a.size(); i += 2)
            dsu.merge(a[i] / 2, a[i + 1] / 2);
        
        return a.size() / 2 - dsu.cc;
    }
};