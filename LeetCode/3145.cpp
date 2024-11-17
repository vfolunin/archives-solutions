class Solution {
    pair<long long, long long> getBitCountAndSumTo(long long value) {
        long long bitCount = 0, sum = 0;
        for (int bit = 0; bit < 50; bit++) {
            long long halfPeriod = 1LL << bit, period = halfPeriod * 2;
            long long curBitCount = value / period * halfPeriod + max(0LL, (value % period) - halfPeriod);
            bitCount += curBitCount;
            sum += curBitCount * bit;
        }
        return { bitCount, sum };
    }

    long long getValue(long long index) {
        long long l = 0, r = 1LL << 50;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (getBitCountAndSumTo(m + 1).first <= index)
                l = m;
            else
                r = m;
        }
        return r;
    }

    long long getSumTo(long long index) {
        long long value = getValue(index);
        auto [bitCount, sum] = getBitCountAndSumTo(value);
        for (int bit = 0; bitCount <= index; bit++) {
            bitCount += value % 2;
            sum += bit * (value % 2);
            value /= 2;
        }
        return sum;
    }

    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1 % mod;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

public:
    vector<int> findProductsOfElements(vector<vector<long long>> &queries) {
        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++) {
            long long sumL = getSumTo(queries[i][0] - 1);
            long long sumR = getSumTo(queries[i][1]);
            res[i] = binPow(2, sumR - sumL, queries[i][2]);
        }
        return res;
    }
};