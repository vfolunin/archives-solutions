class Solution {
public:
    int waysToDistribute(int n, int k) {
        static vector<vector<int>> memo(1001, vector<int>(1001, -1));
        int &res = memo[n][k];
        if (res != -1)
            return res;
        
        if (k == 1 || k == n)
            return res = 1;
        
        static const long long MOD = 1e9 + 7;
        return res = (1LL * waysToDistribute(n - 1, k) * k + waysToDistribute(n - 1, k - 1)) % MOD;
    }
};