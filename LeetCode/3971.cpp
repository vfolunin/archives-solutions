class Solution {
    static const long long MOD = 1e9 + 7;

    pair<long long, long long> getCountAndSum(vector<int> &a, vector<int> &delta, int value) {
        long long count = 0, sum = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] >= value) {
                long long deltaCount = (a[i] - value) / delta[i] + 1;
                count += deltaCount;
                sum = (sum + a[i] * deltaCount - (deltaCount - 1) * deltaCount / 2 * delta[i]) % MOD;
            }
        }
        return { count, sum };
    }

public:
    int maxTotalValue(vector<int> &a, vector<int> &delta, int limit) {
        int l = 0, r = 1e9 + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (getCountAndSum(a, delta, m).first <= limit)
                r = m;
            else
                l = m;
        }

        auto [count, sum] = getCountAndSum(a, delta, r);
        sum = (sum + (limit - count) * l) % MOD;
        return sum;
    }
};