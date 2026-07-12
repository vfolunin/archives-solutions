class Solution {
    static const long long MOD = 1e9 + 7;

    long long binPow(long long x, long long p) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1) * x % MOD;
        long long r = binPow(x, p / 2);
        return r * r % MOD;
    }

    long long inv(long long x) {
        return binPow(x, MOD - 2);
    }

public:
    int minimumCost(vector<int> &a, int delta) {
        long long resourceCount = delta, opCount = 0;
        for (int value : a) {
            if (resourceCount < value) {
                long long ops = (value - resourceCount + delta - 1) / delta;
                opCount = (opCount + ops) % MOD;
                resourceCount += ops * delta;
            }
            resourceCount -= value;
        }
        
        return opCount * (opCount + 1) % MOD * inv(2) % MOD;
    }
};