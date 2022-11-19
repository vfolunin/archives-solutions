struct DSU {
    vector<int> id, size;
    int cc;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        size.assign(n, 1);
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
        cc--;
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
    vector<int> groupStrings(vector<string> &words) {
        unordered_map<int, int> index;
        DSU dsu(words.size());
        
        for (int i = 0; i < words.size(); i++) {
            int mask = 0;
            for (char c : words[i])
                mask |= 1 << (c - 'a');

            if (index.count(mask))
                dsu.merge(i, index[mask]);
            else
                index[mask] = i;
            
            for (int bit = 0; bit < 26; bit++) {
                if (mask & (1 << bit)) {
                    if (index.count(mask ^ (1 << bit)))
                        dsu.merge(i, index[mask ^ (1 << bit)]);
                    
                    for (int bit2 = 0; bit2 < 26; bit2++)
                        if ((mask & (1 << bit)) && index.count((mask ^ (1 << bit)) | (1 << bit2)))
                            dsu.merge(i, index[(mask ^ (1 << bit)) | (1 << bit2)]);
                } else {
                    if (index.count(mask | (1 << bit)))
                        dsu.merge(i, index[mask | (1 << bit)]);
                }
            }
        }
        
        return { dsu.cc, *max_element(dsu.size.begin(), dsu.size.end()) };
    }
};