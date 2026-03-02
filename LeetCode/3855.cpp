class Solution {
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1 % mod;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

public:
    int sumOfNumbers(int l, int r, int size) {
        const long long MOD = 1e9 + 7;

        long long res = (binPow(10, size, MOD) + MOD - 1) % MOD;
        res = res * binPow(9, MOD - 2, MOD) % MOD;
        res = res * ((l + r) * (r - l + 1) / 2) % MOD;
        res = res * binPow(r - l + 1, size - 1, MOD) % MOD;

        return res;
    }
};