class Solution {
public:
    long long maximumSumScore(vector<int> &a) {
        long long lSum = 0, rSum = accumulate(a.begin(), a.end(), 0LL), res = -1e18;
        for (int value : a) {
            lSum += value;
            res = max({ res, lSum, rSum });
            rSum -= value;
        }
        return res;
    }
};