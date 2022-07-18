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
    int countGoodNumbers(long long n) {
        const long long MOD = 1e9 + 7;
        
        long long oddCount = n / 2;
        long long evenCount = n - oddCount;
        
        return binPow(4, oddCount, MOD) * binPow(5, evenCount, MOD) % MOD;
    }
};