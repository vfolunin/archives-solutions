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
    int monkeyMove(int n) {
        long long MOD = 1e9 + 7;
        long long res = binPow(2, n, MOD);
        res = (res + MOD - 2) % MOD;
        return res;
    }
};