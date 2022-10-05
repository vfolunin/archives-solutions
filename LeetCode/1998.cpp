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
    bool gcdSort(vector<int> &a) {
        DSU dsu(1e5 + 1);
        
        for (int value : a) {
            int v = value;
            for (int d = 2; d * d <= value; d++) {
                if (v % d == 0) {
                    dsu.merge(value, d);
                    while (v % d == 0)
                        v /= d;
                }
            }
            if (v > 1)
                dsu.merge(value, v);
        }
        
        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());
        
        for (int i = 0; i < a.size(); i++)
            if (!dsu.connected(a[i], sortedA[i]))
                return 0;
        return 1;
    }
};