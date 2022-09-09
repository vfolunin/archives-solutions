class Solution {
    const long long MOD = 1e9 + 7;
    
    long long c(int n, int k) {
        if (k > n || k < 0)
            return 0;

        static vector<vector<long long>> memo(1001, vector<long long>(1001, -1));
        if (memo[n][k] != -1)
            return memo[n][k];

        if (k == 0 || k == n)
            return memo[n][k] = 1;

        return memo[n][k] = (c(n - 1, k) + c(n - 1, k - 1)) % MOD;
    }
    
public:
    int numberOfWays(int a, int b, int k) {
        int dist = abs(a - b);
        if ((k - dist) % 2)
            return 0;    
        return c(k, (k - dist) / 2);
    }
};