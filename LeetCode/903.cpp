class Solution {
    const long long MOD = 1e9 + 7;
    
    long long rec(int i, int last, string &s, vector<vector<long long>> &memo) {
        long long &res = memo[i][last];
        if (res != -1)
            return res;
        
        if (i == 0)
            return res = 1;
        
        res = 0;
        if (s[i - 1] == 'D') {
            for (int prev = last; prev < i; prev++)
                res = (res + rec(i - 1, prev, s, memo)) % MOD;
        } else {
            for (int prev = 0; prev < last; prev++)
                res = (res + rec(i - 1, prev, s, memo)) % MOD;
        }
        return res;
    }
    
public:
    int numPermsDISequence(string &s) {
        vector<vector<long long>> memo(s.size() + 1, vector<long long>(s.size() + 1, -1));
        long long res = 0;
        
        for (int last = 0; last <= s.size(); last++)
            res = (res + rec(s.size(), last, s, memo)) % MOD;
        
        return res;
    }
};