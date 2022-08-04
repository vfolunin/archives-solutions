class Solution {
    bool isSubset(vector<int> &a, vector<int> &b) {
        int bi = 0;
        for (int ai = 0; ai < a.size() && bi < b.size(); ai++)
            bi += a[ai] == b[bi];
        return bi == b.size();
    }
    
public:
    vector<int> peopleIndexes(vector<vector<string>> &a) {
        unordered_map<string, int> id;
        vector<vector<int>> h(a.size());
        
        for (int i = 0; i < a.size(); i++) {
            for (string &s : a[i]) {
                if (!id.count(s))
                    id[s] = id.size();
                h[i].push_back(id[s]);
            }
            sort(h[i].begin(), h[i].end());
        }
        
        vector<int> res;
        for (int i = 0; i < h.size(); i++) {
            bool ok = 1;
            for (int j = 0; ok && j < h.size(); j++)
                ok &= i == j || !isSubset(h[j], h[i]);
            if (ok)
                res.push_back(i);
        }
        return res;
    }
};