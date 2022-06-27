class Solution {
public:
    int mctFromLeafValues(vector<int> &a) {
        vector<vector<int>> maxValue(a.size(), vector<int>(a.size()));
        for (int l = 0; l < a.size(); l++) {
            maxValue[l][l] = a[l];
            for (int r = l + 1; r < a.size(); r++)
                maxValue[l][r] = max(maxValue[l][r - 1], a[r]);
        }
        
        vector<vector<int>> res(a.size(), vector<int>(a.size()));
        
        for (int len = 2; len <= a.size(); len++) {
            for (int l = 0, r = len - 1; r < a.size(); l++, r++) {
                res[l][r] = res[l][l] + res[l + 1][r] + maxValue[l][l] * maxValue[l + 1][r];
                for (int m = l + 1; m < r; m++)
                    res[l][r] = min(res[l][r], res[l][m] + res[m + 1][r] + maxValue[l][m] * maxValue[m + 1][r]);
            }
        }
        
        return res[0][a.size() - 1];
    }
};