class Solution {
    long long rec(vector<int> &a, int mask, int gain, vector<long long> &memo) {
        long long &res = memo[mask];
        if (res != -1)
            return res;
        
        if (!mask)
            return res = 0;
        
        res = 1e18;
        for (int i = 0; i < a.size(); i++)
            if (mask & (1 << i))
                res = min(res, (a[i] + gain - 1) / gain + rec(a, mask ^ (1 << i), gain + 1, memo));
        return res;
    }

public:
    long long minimumTime(vector<int> &a) {
        vector<long long> memo(1 << a.size(), -1);
        return rec(a, (1 << a.size()) - 1, 1, memo);
    }
};