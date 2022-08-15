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
    int minimumHammingDistance(vector<int> &a, vector<int> &b, vector<vector<int>> &swaps) {
        DSU dsu(a.size());
        for (vector<int> &swap : swaps)
            dsu.merge(swap[0], swap[1]);
        
        unordered_map<int, pair<unordered_map<int, int>, unordered_map<int, int>>> counts;
        for (int i = 0; i < a.size(); i++) {
            counts[dsu.find(i)].first[a[i]]++;
            counts[dsu.find(i)].second[b[i]]++;
        }
        
        int res = a.size();
        for (auto &[index, countPair] : counts) {
            auto &[countA, countB] = countPair;
            for (auto &[key, ca] : countA)
                res -= min(ca, countB.count(key) ? countB[key] : 0);
        }
        return res;
    }
};