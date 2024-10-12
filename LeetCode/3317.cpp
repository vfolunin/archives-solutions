class Solution {
    const long long MOD = 1e9 + 7;

    long long c(int n, int k) {
        static vector<vector<long long>> memo(1001, vector<long long>(1001, -1));
        long long &res = memo[n][k];
        if (res != -1)
            return res;

        if (k == 0 || k == n)
            return res = 1;

        return res = (c(n - 1, k) + c(n - 1, k - 1)) % MOD;
    }

    long long stirling2(int n, int k) {
        static vector<vector<long long>> memo(1001, vector<long long>(1001, -1));
        long long &res = memo[n][k];
        if (res != -1)
            return res;

        if (n < k)
            return res = 0;
        if (k == 1)
            return res = 1;

        return res = (stirling2(n - 1, k) * k + stirling2(n - 1, k - 1)) % MOD;
    }

    long long factorial(int n) {
        static vector<long long> memo(1001);
        long long &res = memo[n];
        if (res)
            return res;

        if (n <= 1)
            return res = 1;

        return res = factorial(n - 1) * n % MOD;
    }
 
    long long binPow(long long x, long long p) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1) * x % MOD;
        long long r = binPow(x, p / 2);
        return r * r % MOD;
    }

public:
    int numberOfWays(int performers, int maxStages, int maxPoints) {
        long long res = 0;
        for (int stages = 1; stages <= performers && stages <= maxStages; stages++) {
            long long ways = c(maxStages, stages);
            ways = ways * stirling2(performers, stages) % MOD;
            ways = ways * factorial(stages) % MOD;
            ways = ways * binPow(maxPoints, stages) % MOD;
            res = (res + ways) % MOD;
        }
        return res;

    }
};