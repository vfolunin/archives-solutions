class Solution {
    static const long long MOD = 1e9 + 7;

    int getOnes(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }

    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

    long long c(int n, int k) {
        if (n < k)
            return 0;

        static vector<vector<long long>> memo(100, vector<long long>(100, -1));
        long long &res = memo[n][k];
        if (res != -1)
            return res;

        if (k == 0 || k == n)
            return res = 1;

        return res = (c(n - 1, k) + c(n - 1, k - 1)) % MOD;
    }

    long long rec(vector<int> &a, int i, int size, int targetSize, int ones, int targetOnes, int carry,
                  vector<vector<vector<vector<long long>>>> &memo) {
        if (size == targetSize)
            return ones + getOnes(carry) == targetOnes;
        if (i == a.size() || size > targetSize || ones > targetOnes)
            return 0;

        long long &res = memo[i][size][ones][carry];
        if (res != -1)
            return res;
        
        res = 0;
        for (int take = 0; size + take <= targetSize; take++) {
            long long ways = c(targetSize - size, take) * binPow(a[i], take, MOD) % MOD;
            int nextSize = size + take;
            int nextOnes = ones + (carry + take) % 2;
            int nextCarry = (carry + take) / 2;
            res = (res + ways * rec(a, i + 1, nextSize, targetSize, nextOnes, targetOnes, nextCarry, memo)) % MOD;
        }
        return res;
    }

public:
    int magicalSum(int targetSize, int targetOnes, vector<int> &a) {
        vector memo(a.size(), vector(targetSize + 1, vector(targetOnes + 1, vector<long long>(targetSize * 2 + 1, -1))));
        return rec(a, 0, 0, targetSize, 0, targetOnes, 0, memo);
    }
};