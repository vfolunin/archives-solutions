class Solution {
public:
    int maxSubarraySumCircular(vector<int> &a) {
        int sum = 0, curMinSum = 0, curMaxSum = 0, minSum = 0, maxSum = a[0];
        for (int value : a) {
            sum += value;
            curMinSum = min(value, value + curMinSum);
            curMaxSum = max(value, value + curMaxSum);
            minSum = min(minSum, curMinSum);
            maxSum = max(maxSum, curMaxSum);
        }
        return maxSum > 0 ? max(maxSum, sum - minSum) : maxSum;
    }
};