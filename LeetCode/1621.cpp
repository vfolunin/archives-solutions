class Solution {
    const long long MOD = 1e9 + 7;
    
    long long rec(int n, int k, int closed) {
        static vector<vector<vector<long long>>> memo(1001, vector<vector<long long>>(1001, vector<long long>(2, -1)));
        long long &res = memo[n][k][closed];
        if (res != -1)
            return res;
        
        if (k == 0) 
            return res = 1;
        
        if (n == 0)
            return res = 0;
        
        res = 0;
        if (closed) {
            res = (res + rec(n - 1, k, 0)) % MOD;
            res = (res + rec(n - 1, k, 1)) % MOD;
        } else {
            res = (res + rec(n - 1, k, 0)) % MOD;
            res = (res + rec(n, k - 1, 1)) % MOD;
        }
        return res;
    }
    
public:
    int numberOfSets(int n, int k) {
        return rec(n, k, 1);
    }
};