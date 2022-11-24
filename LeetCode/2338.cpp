class Solution {
    void rec(int size, int maxSize, int value, int maxValue, vector<int> &count) {
        if (size > maxSize)
            return;
        
        count[size]++;
        for (int factor = 2; value * factor <= maxValue; factor++)
            rec(size + 1, maxSize, value * factor, maxValue, count);
    }
    
    const long long MOD = 1e9 + 7;
    
    vector<long long> precalcFactorials() {
        vector<long long> memo(1e5);
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
    int idealArrays(int maxSize, int maxValue) {
        vector<int> count(maxSize + 1);
        for (int value = 1; value <= maxValue; value++)
            rec(1, maxSize, value, maxValue, count);
        
        long long res = 0;
        for (int size = 1; size <= maxSize; size++)
            res = (res + count[size] * c(maxSize - 1, size - 1)) % MOD;
        return res;
    }
};