class Solution {
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

public:
    int countDistinctStrings(string &s, int k) {
        return binPow(2, s.size() - k + 1, 1e9 + 7);
    }
};