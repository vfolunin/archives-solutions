struct Counter {
    inline static const long long MOD = 1e9 + 7;
    unordered_map<int, int> count;
    long long sum = 0;

    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

    void add(int value, int delta) {
        if (count[value])
            sum = (sum - binPow(value, count[value], MOD) + MOD) % MOD;
        count[value] += delta;
        if (count[value])
            sum = (sum + binPow(value, count[value], MOD)) % MOD;
    }
};

class Solution {
public:
    int maxFrequencyScore(vector<int> &a, int width) {
        Counter counter;
        for (int i = 0; i < width; i++)
            counter.add(a[i], 1);
        long long res = counter.sum;

        for (int i = width; i < a.size(); i++) {
            counter.add(a[i - width], -1);
            counter.add(a[i], 1);
            res = max(res, counter.sum);
        }

        return res;
    }
};