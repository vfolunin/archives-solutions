class Solution {
    int rec(vector<int> &a, int i, int d, vector<int> &memo) {
        int &res = memo[i];
        if (res != -1)
            return res;
        
        res = 0;
        for (int j = 1; j <= d && i - j >= 0 && a[i] > a[i - j]; j++)
            res = max(res, 1 + rec(a, i - j, d, memo));
        for (int j = 1; j <= d && i + j < a.size() && a[i] > a[i + j]; j++)
            res = max(res, 1 + rec(a, i + j, d, memo));
        return res;
    }
    
public:
    int maxJumps(vector<int> &a, int d) {
        int res = 0;
        vector<int> memo(a.size(), -1);
        for (int i = 0; i < a.size(); i++)
            res = max(res, rec(a, i, d, memo));
        return res + 1;
    }
};