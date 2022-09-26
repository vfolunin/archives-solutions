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

    vector<long long> getF() {
        vector<long long> f(2e4 + 1);
        f[0] = 1;
        for (int i = 1; i < f.size(); i++)
            f[i] = f[i - 1] * i % MOD;
        return f;
    }

    long long c(int n, int m) {
        static vector<long long> f = getF();
        return f[n] * inv(f[m]) % MOD * inv(f[n - m]) % MOD;
    }
    
    map<int, int> factorize(int n) {
        map<int, int> factorization;

        for (long long d = 2; d * d <= n; d++) {
            while (n % d == 0) {
                factorization[d]++;
                n /= d;
            }
        }
        if (n != 1)
           factorization[n]++;

        return factorization;
    }
    
    int solve(int size, int product) {
        long long res = 1;
        for (auto &[d, count] : factorize(product))
            res = res * c(size + count - 1, size - 1) % MOD;
        return res;
    }
    
public:
    vector<int> waysToFillArray(vector<vector<int>> &queries) {
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
            res[i] = solve(queries[i][0], queries[i][1]);
        return res;
    }
};