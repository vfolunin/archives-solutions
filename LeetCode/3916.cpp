class Solution {
    static const long long MOD = 1e9 + 7;

    long long getSum(vector<long long> &p, int l, int r) {
        if (l > r)
            return 0;
        return ((p[r] - (l ? p[l - 1] : 0)) % MOD + MOD) % MOD;
    }

    long long getWays(int size, int valueCount) {
        if (valueCount <= 1)
            return 0;

        vector pWays(size, vector(2, vector<long long>(valueCount + 1)));
        for (int value = 0; value < valueCount; value++) {
            pWays[0][0][value] = (1 + (value ? pWays[0][0][value - 1] : 0)) % MOD;
            pWays[0][1][value] = (1 + (value ? pWays[0][1][value - 1] : 0)) % MOD;
        }

        for (int i = 1; i < size; i++) {
            for (int value = 0; value < valueCount; value++) {
                pWays[i][0][value] = (getSum(pWays[i - 1][1], value + 1, valueCount - 1) + (value ? pWays[i][0][value - 1] : 0)) % MOD;
                pWays[i][1][value] = (getSum(pWays[i - 1][0], 0, value - 1) + (value ? pWays[i][1][value - 1] : 0)) % MOD;
            }
        }

        return (getSum(pWays.back()[0], 0, valueCount - 1) + getSum(pWays.back()[1], 0, valueCount - 1)) % MOD;
    }

    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1 % mod;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

    long long inv(long long x) {
        return binPow(x, MOD - 2, MOD);
    }

public:
    int zigZagArrays(int size, int l, int r) {
        long long valueCount = r - l + 1;
        int pointCount = size + 1;

        vector<long long> x(pointCount), y(pointCount);
        for (int i = 0; i < pointCount; i++) {
            x[i] = i + 1;
            y[i] = getWays(size, x[i]);
        }

        vector<long long> pl(pointCount);
        for (int i = 0; i < pointCount; i++)
            pl[i] = ((valueCount - x[i]) % MOD + MOD) % MOD * (i ? pl[i - 1] : 1) % MOD;

        vector<long long> pr(pointCount);
        for (int i = pointCount - 1; i >= 0; i--)
            pr[i] = ((valueCount - x[i]) % MOD + MOD) % MOD * (i + 1 < pointCount ? pr[i + 1] : 1) % MOD;

        long long res = 0;
        for (int i = 0; i < pointCount; i++) {
            long long num = (i ? pl[i - 1] : 1) * (i + 1 < pointCount ? pr[i + 1] : 1) % MOD;

            long long den = 1;
            for (int j = 0; j < pointCount; j++)
                if (i != j)
                    den = den * ((x[i] - x[j] + MOD) % MOD) % MOD;

            res = (res + y[i] * num % MOD * inv(den) % MOD) % MOD;
        }
        return res;
    }
};