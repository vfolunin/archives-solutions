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
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        map<int, vector<pair<int, int>>> pos;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                pos[a[y][x]].push_back({ y, x });
        
        vector<int> rank(h + w);
        for (auto &[_, cells] : pos) {
            DSU dsu(h + w);
            unordered_set<int> used;
            for (auto &[y, x] : cells) {
                dsu.merge(y, h + x);
                used.insert(y);
                used.insert(h + x);
            }
            
            unordered_map<int, int> newRank;
            for (int i : used)
                newRank[dsu.find(i)] = max(newRank[dsu.find(i)], rank[i]);
            
            for (auto &[y, x] : cells)
                a[y][x] = rank[y] = rank[h + x] = newRank[dsu.find(y)] + 1;
        }
        
        return a;
    }
};