class Solution {
public:
    int maxNonDecreasingLength(vector<int> &a, vector<int> &b) {
        vector<vector<int>> maxLen(a.size(), vector<int>(2, 1));
        int res = 1;
        
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] <= a[i])
                maxLen[i][0] = max(maxLen[i][0], maxLen[i - 1][0] + 1);
            if (b[i - 1] <= a[i])
                maxLen[i][0] = max(maxLen[i][0], maxLen[i - 1][1] + 1);
    
            if (a[i - 1] <= b[i])
                maxLen[i][1] = max(maxLen[i][1], maxLen[i - 1][0] + 1);
            if (b[i - 1] <= b[i])
                maxLen[i][1] = max(maxLen[i][1], maxLen[i - 1][1] + 1);
            
            res = max({ res, maxLen[i][0], maxLen[i][1] });
        }
        
        return res;
    }
};