class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int> &a) {
        long long posSum = -1e18, negSum = -1e18, res = -1e18;
        for (int value : a) {
            long long prevPosSum = posSum;
            posSum = max<long long>(value, negSum + value);
            negSum = prevPosSum - value;
            res = max({ res, posSum, negSum });
        }
        return res;
    }
};