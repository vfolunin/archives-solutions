class Solution {
    const long long MOD = 1e9 + 7;

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

    long long factorial(int n) {
        long long res = 1;
        for (int i = 1; i <= n; i++)
            res = res * i % MOD;
        return res;
    }
    
public:
    int countOrders(int n) {
        return factorial(2 * n) * inv(binPow(2, n, MOD)) % MOD;
    }
};