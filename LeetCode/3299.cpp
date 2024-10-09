class Solution {
public:
    int getSum(vector<int> &a) {
        const long long MOD = 1e9 + 7;
        int maxValue = *max_element(a.begin(), a.end());
        vector<pair<long long, long long>> inc(maxValue + 2), dec(maxValue + 2);

        for (int value : a) {
            inc[value] = {
                (inc[value].first + 1 + inc[value - 1].first) % MOD,
                (inc[value].second + value * (1 + inc[value - 1].first) % MOD + inc[value - 1].second) % MOD
            };
            dec[value] = {
                (dec[value].first + 1 + dec[value + 1].first) % MOD,
                (dec[value].second + value * (1 + dec[value + 1].first) % MOD + dec[value + 1].second) % MOD
            };
        }

        long long res = 0;
        for (const vector<pair<long long, long long>> &a : { inc, dec })
            for (auto &[count, sum] : a)
                res = (res + sum) % MOD;
        for (int value : a)
            res = (res - value + MOD) % MOD;
        return res;
    }
};