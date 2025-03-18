class Solution {
public:
    vector<int> solveQueries(vector<int> &a, vector<int> &queries) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
        
        vector<int> res(queries.size(), -1);
        for (int i = 0; i < res.size(); i++) {
            const vector<int> &p = pos[a[queries[i]]];
            if (p.size() > 1) {
                int j = lower_bound(p.begin(), p.end(), queries[i]) - p.begin();
                int j1 = (j + 1) % p.size();
                int j2 = (j + p.size() - 1) % p.size();
                int d1 = abs(p[j] - p[j1]);
                d1 = min<int>(d1, a.size() - d1);
                int d2 = abs(p[j] - p[j2]);
                d2 = min<int>(d2, a.size() - d2);
                res[i] = min(d1, d2);
            }
        }
        return res;
    }
};