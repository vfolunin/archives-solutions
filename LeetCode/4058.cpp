class Solution {
public:
    long long maxValue(vector<int> &a) {
        long long prefixAltSum = 0;
        long long minDelta = 1e18;
        vector<long long> maxPrevPrefixAltSum = { (long long)-1e18, 0 };

        for (int i = 0; i < a.size(); i++) {
            prefixAltSum += a[i] * (i % 2 ? -1 : 1);
            minDelta = min(minDelta, prefixAltSum - maxPrevPrefixAltSum[i % 2]);
            maxPrevPrefixAltSum[i % 2] = max(maxPrevPrefixAltSum[i % 2], prefixAltSum);
        }

        return prefixAltSum - min(2 * minDelta, 0LL);
    }
};