class Solution {
    const long long MOD = 1e9 + 7;

    long long getCatalan(int n) {
        vector<long long> res = { 1 };
        for (int i = 1; i <= n; i++) {
            res.push_back(0);
            for (int j = 0; j < i; j++)
                res.back() = (res.back() + res[j] * res[i - 1 - j]) % MOD;
        }
        return res.back();
    }

public:
    int numberOfWays(int n) {
        return getCatalan(n / 2);
    }
};