struct DSU {
    vector<int> id, size;

    DSU(int n) {
        size.assign(n, 1);
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
    int maxActivated(vector<vector<int>> &points) {
        vector<int> order(points.size());
        iota(order.begin(), order.end(), 0);
        DSU dsu(points.size());

        sort(order.begin(), order.end(), [&](int l, int r) {
            return points[l][0] < points[r][0];
        });
        for (int i = 1; i < order.size(); i++)
            if (points[order[i - 1]][0] == points[order[i]][0])
                dsu.merge(order[i - 1], order[i]);
                
        sort(order.begin(), order.end(), [&](int l, int r) {
            return points[l][1] < points[r][1];
        });
        for (int i = 1; i < order.size(); i++)
            if (points[order[i - 1]][1] == points[order[i]][1])
                dsu.merge(order[i - 1], order[i]);
        
        vector<int> sizes;
        for (int v = 0; v < points.size(); v++)
            if (dsu.id[v] == v)
                sizes.push_back(dsu.size[v]);
        sort(sizes.rbegin(), sizes.rend());

        int res = 1;
        for (int i = 0; i < 2 && i < sizes.size(); i++)
            res += sizes[i];
        return res;
    }
};