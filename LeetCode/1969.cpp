class Solution {
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }
    
public:
    int minNonZeroProduct(int n) {
        const long long MOD = 1e9 + 7;
        
        long long a = ((1LL << n) - 2 + MOD) % MOD;
        long long b = (1LL << (n - 1)) - 1;
        long long c = ((1LL << n) - 1 + MOD) % MOD;
        
        return binPow(a, b, MOD) * c % MOD;
    }
};