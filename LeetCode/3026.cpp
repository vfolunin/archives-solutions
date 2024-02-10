class Solution {
public:
    long long maximumSubarraySum(vector<int> &a, int diff) {
        long long prefixSum = 0, res = -1e18;
        unordered_map<int, long long> minPrefixSum;

        for (int value : a) {
            for (int startValue : { value - diff, value + diff })
                if (minPrefixSum.count(startValue))
                    res = max(res, prefixSum + value - minPrefixSum[startValue]);

            if (minPrefixSum.count(value))
                minPrefixSum[value] = min(minPrefixSum[value], prefixSum);
            else
                minPrefixSum[value] = prefixSum;

            prefixSum += value;
        }

        return res != -1e18 ? res : 0;
    }
};