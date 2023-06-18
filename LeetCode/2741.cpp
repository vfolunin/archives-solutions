class Solution {
    const long long MOD = 1e9 + 7;

    long long rec(vector<int> &a, int mask, int last, vector<vector<long long>> &memo) {
        long long &res = memo[mask][last];
        if (res != -1)
            return res;
        
        if (!(mask & (mask - 1)))
            return res = 1;
        
        res = 0;        
        for (int prev = 0; prev < a.size(); prev++)
            if (prev != last && (mask & (1 << prev)) && (a[last] % a[prev] == 0 || a[prev] % a[last] == 0))
                res = (res + rec(a, mask ^ (1 << last), prev, memo)) % MOD;
        return res;
    }
    
public:
    int specialPerm(vector<int> &a) {
        vector<vector<long long>> memo(1 << a.size(), vector<long long>(a.size(), -1));
        long long res = 0;

        for (int last = 0; last < a.size(); last++)
            res = (res + rec(a, (1 << a.size()) - 1, last, memo)) % MOD;
            
        return res;
    }
};