class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long xoredA = a >> n << n, xoredB = b >> n << n;

        for (int bit = n - 1; bit >= 0; bit--) {
            if ((a & (1LL << bit)) == (b & (1LL << bit))) {
                xoredA |= 1LL << bit;
                xoredB |= 1LL << bit;
            } else if (xoredA <= xoredB) {
                xoredA |= 1LL << bit;
            } else {
                xoredB |= 1LL << bit;
            }
        }

        const long long MOD = 1e9 + 7;
        xoredA %= MOD;
        xoredB %= MOD;
        return xoredA * xoredB % MOD;
    }
};