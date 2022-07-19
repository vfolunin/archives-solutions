class Solution {
public:
    long long mostPoints(vector<vector<int>> &q) {
        vector<long long> res(q.size());
        res.back() = q.back()[0];
        
        for (int i = (int)res.size() - 2; i >= 0; i--)
            res[i] = max<long long>(
                q[i][0] + (i + q[i][1] + 1 < res.size() ? res[i + q[i][1] + 1] : 0),
                res[i + 1]
            );
        
        return res[0];
    }
};