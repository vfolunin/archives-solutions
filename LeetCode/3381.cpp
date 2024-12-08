class Solution {
public:
    long long maxSubarraySum(vector<int> &a, int mod) {
        vector<long long> minSum(mod, 1e18);
        minSum[mod - 1] = 0;

        long long pSum = 0, res = -1e18;
        for (int i = 0; i < a.size(); i++) {
            pSum += a[i];
            res = max(res, pSum - minSum[i % mod]);
            minSum[i % mod] = min(minSum[i % mod], pSum);
        }
        return res;
    }
};