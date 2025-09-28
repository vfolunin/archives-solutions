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
    long long maxAlternatingSum(vector<int> &a, vector<vector<int>> &swaps) {
        DSU dsu(a.size());
        for (vector<int> &swap : swaps)
            dsu.merge(swap[0], swap[1]);
        
        unordered_map<int, deque<int>> groups;
        for (int i = 0; i < a.size(); i++)
            groups[dsu.find(i)].push_back(a[i]);
        
        for (auto &[_, group] : groups)
            sort(group.begin(), group.end());
        
        long long res = 0;
        for (int i = 0; i < a.size(); i++) {
            deque<int> &group = groups[dsu.find(i)];
            if (i % 2) {
                res -= group.front();
                group.pop_front();
            } else {
                res += group.back();
                group.pop_back();
            }
        }
        return res;
    }
};