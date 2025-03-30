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
    int numberOfComponents(vector<vector<int>> &a, int threshold) {
        for (vector<int> &a : a)
            sort(a.begin(), a.end());

        DSU dsu(a.size());

        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                vector<int> common;
                for (int value : a[i])
                    if ((common.empty() || common.back() != value) && binary_search(a[j].begin(), a[j].end(), value))
                        common.push_back(value);
                
                if (common.size() >= threshold)
                    dsu.merge(i, j);
            }
        }

        return dsu.cc;
    }
};