class Solution {
public:
    long long minArraySum(vector<int> &a, int mod) {
        vector<long long> minSum(mod, 1e18);
        minSum[0] = 0;

        long long sum = 0;
        for (int value : a) {
            sum += value;
            minSum[sum % mod] = min(minSum[sum % mod], sum);
            sum = minSum[sum % mod];
        }
        return sum;
    }
};