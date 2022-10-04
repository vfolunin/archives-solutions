class Solution {
public:
    int maxDotProduct(vector<int> &a, vector<int> &b) {
        vector<vector<int>> res(a.size() + 1, vector<int>(b.size() + 1, -1e9));
        res[0][0] = 0;
        
        for (int ai = 1; ai <= a.size(); ai++) {
            for (int bi = 1; bi <= b.size(); bi++) {
                res[ai][bi] = max({
                    a[ai - 1] * b[bi - 1],
                    res[ai - 1][bi - 1] + a[ai - 1] * b[bi - 1],
                    res[ai - 1][bi],
                    res[ai][bi - 1]
                });
            }
        }
        
        return res[a.size()][b.size()];
    }
};