class Solution {
public:
    vector<int> xorQueries(vector<int> &p, vector<vector<int>>& queries) {
        for (int i = 1; i < p.size(); i++)
            p[i] ^= p[i - 1];
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
            res[i] = p[queries[i][1]] ^ (queries[i][0] ? p[queries[i][0] - 1] : 0);
        
        return res;
    }
};