class Solution {
public:
    int countValidSubarrays(vector<int> &a, int digit) {
        vector<vector<long long>> prefixSum(10);
        prefixSum[0].push_back(0);

        long long sum = 0, res = 0;
        for (int value : a) {
            sum += value;
            int remainder = ((sum - digit) % 10 + 10) % 10;

            for (long long power = 1; digit * power <= sum; power *= 10) {
                long long l = sum - (digit + 1) * power + 1;
                long long r = sum - digit * power;

                res += upper_bound(prefixSum[remainder].begin(), prefixSum[remainder].end(), r) -
                       lower_bound(prefixSum[remainder].begin(), prefixSum[remainder].end(), l);
            }

            prefixSum[sum % 10].push_back(sum);
        }
        return res;
    }
};