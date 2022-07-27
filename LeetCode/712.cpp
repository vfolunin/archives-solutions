class Solution {
public:
    int minimumDeleteSum(string &a, string &b) {
        vector<vector<int>> res(a.size() + 1, vector<int>(b.size() + 1));
        
        for (int ai = 1; ai <= a.size(); ai++)
            res[ai][0] = res[ai - 1][0] + a[ai - 1];
        
        for (int bi = 1; bi <= b.size(); bi++)
            res[0][bi] = res[0][bi - 1] + b[bi - 1];
        
        for (int ai = 1; ai <= a.size(); ai++) {
            for (int bi = 1; bi <= b.size(); bi++) {
                if (a[ai - 1] == b[bi - 1])
                    res[ai][bi] = res[ai - 1][bi - 1];
                else
                    res[ai][bi] = min(res[ai - 1][bi] + a[ai - 1], res[ai][bi - 1] + b[bi - 1]);
            }
        }
        
        return res[a.size()][b.size()];
    }
};