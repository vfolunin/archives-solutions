class Solution {
public:
    int findLength(vector<int> &a, vector<int> &b) {
        vector<vector<int>> lcs(a.size() + 1, vector<int>(b.size() + 1));
        int res = 0;
        for (int ai = 1; ai <= a.size(); ai++) {
            for (int bi = 1; bi <= b.size(); bi++) {
                if (a[ai - 1] == b[bi - 1])
                    lcs[ai][bi] = lcs[ai - 1][bi - 1] + 1;
                else
                    lcs[ai][bi] = 0;
                res = max(res, lcs[ai][bi]);
            }
        }
        return res;
    }
};