class Solution {
    long long getSum(vector<long long> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }

public:
    int numberOfWays(int n, vector<int> &limit) {
        for (int &value : limit)
            value = min(value, n - 1);
        sort(limit.begin(), limit.end());

        vector<long long> pSum(limit.begin(), limit.end());
        partial_sum(pSum.begin(), pSum.end(), pSum.begin());

        const long long MOD = 1e9 + 7;
        long long res = 0;
        for (int i = 0; i < limit.size(); i++) {
            int j = lower_bound(limit.begin() + i + 1, limit.end(), n - limit[i]) - limit.begin();
            long long ways = getSum(pSum, j, limit.size() - 1) - (n - 1LL - limit[i]) * (limit.size() - j);
            res = (res + ways) % MOD;
        }
        res = res * 2 % MOD;
        return res;
    }
};