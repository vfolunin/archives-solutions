class Solution {
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
        static unordered_map<long long, long long> memo;
        if (memo.count(x))
            return memo[x];
        return memo[x] = binPow(x, MOD - 2, MOD);
    }

    long long c(int n, int k) {
        return k <= n ? factorial(n) * inv(factorial(k)) % MOD * inv(factorial(n - k)) % MOD : 0;
    }

public:
    int minMaxSums(vector<int> &a, int sizeLimit) {
        sort(a.begin(), a.end());

        long long res = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int size = 1; size <= sizeLimit; size++) {
                res = (res + a[i] * c(i, size - 1) % MOD) % MOD;
                res = (res + a[i] * c(a.size() - i - 1, size - 1) % MOD) % MOD;
            }
        }
        return res;
    }
};