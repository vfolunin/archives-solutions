class Solution {
    int rec(vector<int> &a, int i, int days, vector<vector<int>> &memo) {
        int &res = memo[i][days];
        if (res != -1)
            return res;
        
        if (days > i + 1)
            return res = 1e9;
        
        if (days == 1)
            return res = *max_element(a.begin(), a.begin() + i + 1);
        
        int last = a[i];
        res = rec(a, i - 1, days - 1, memo) + last;
        
        for (int j = i - 1; j; j--) {
            last = max(last, a[j]);
            res = min(res, rec(a, j - 1, days - 1, memo) + last);
        }
        
        return res;
    }
    
public:
    int minDifficulty(vector<int> &a, int days) {
        vector<vector<int>> memo(a.size(), vector<int>(days + 1, -1));
        int res = rec(a, a.size() - 1, days, memo);
        return res != 1e9 ? res : -1;
    }
};