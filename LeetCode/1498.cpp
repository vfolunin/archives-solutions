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
    int numSubseq(vector<int> &a, int limit) {
        sort(a.begin(), a.end());

        long long res = 0;
        const long long MOD = 1e9 + 7;

        for (int l = 0, r = a.size() - 1; l <= r; l++) {
            while (l <= r && a[l] + a[r] > limit)
                r--;

            if (l <= r)
                res = (res + binPow(2, r - l, MOD)) % MOD;
        }

        return res;
    }
};