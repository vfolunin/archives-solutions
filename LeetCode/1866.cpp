class Solution {
    long long rec(int n, int k) {    
        static vector<vector<long long>> memo(1001, vector<long long>(1001, -1));
        long long &res = memo[n][k];
        if (res != -1)
            return res;
        
        if (k == 0 || k > n)
            return res = 0;
        if (n <= 2)
            return res = 1;
        
        const long long MOD = 1e9 + 7;
        return res = (rec(n - 1, k - 1) + (n - 1) * rec(n - 1, k)) % MOD;
    }
    
public:
    int rearrangeSticks(int n, int k) {
        return rec(n, k);
    }
};