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
    int countComponents(vector<int> &a, int limit) {
        DSU dsu(limit + 1);
        for (int value : a)
            for (int multiple = value * 2; multiple <= limit; multiple += value)
                dsu.merge(value, multiple);

        unordered_set<int> ids;
        for (int value : a)
            ids.insert(value <= limit ? dsu.find(value) : value);
        return ids.size();
    }
};