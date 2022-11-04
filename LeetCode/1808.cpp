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
    int maxNiceDivisors(int n) {
        const long long MOD = 1e9 + 7;
        
        if (n % 3 == 0)
            return binPow(3, n / 3, MOD);
        else if (n % 3 == 1)
            return n == 1 ? 1 : 4 * binPow(3, n / 3 - 1, MOD) % MOD;
        else
            return 2 * binPow(3, n / 3, MOD) % MOD;
    }
};