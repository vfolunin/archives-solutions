class Solution {
public:
    int sumOfGoodSubsequences(vector<int> &a) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, long long> sum, count;

        for (int value : a) {
            for (int prevValue : { value - 1, value + 1 }) {
                sum[value] = (sum[value] + sum[prevValue] + count[prevValue] * value) % MOD;
                count[value] = (count[value] + count[prevValue]) % MOD;
            }
            sum[value] = (sum[value] + value) % MOD;
            count[value] = (count[value] + 1) % MOD;
        }

        long long res = 0;
        for (auto &[_, sum] : sum)
            res = (res + sum) % MOD;
        return res;
    }
};