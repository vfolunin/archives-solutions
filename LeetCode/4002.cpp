class Solution {
    static const long long MOD = 1e9 + 7;

    vector<long long> precalcFactorials() {
        vector<long long> memo(5e5 + 1);
        memo[0] = 1;
        for (int i = 1; i < memo.size(); i++)
            memo[i] = memo[i - 1] * i % MOD;
        return memo;
    }

    long long factorial(int n) {
        static vector<long long> memo = precalcFactorials();
        return memo[n];
    }
 
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

    long long inv(long long x) {
        return binPow(x, MOD - 2, MOD);
    }

    long long c(int n, int k) {
        return factorial(n) * inv(factorial(k)) % MOD * inv(factorial(n - k)) % MOD;
    }

public:
    int countValidSequences(int targetSum, int size) {
        return (c(targetSum - 1, size - 1) - ((targetSum + size) % 2 ? 0 : c((targetSum + size) / 2 - 1, size - 1)) + MOD) % MOD;
    }
};