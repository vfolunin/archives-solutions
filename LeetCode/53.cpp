class Solution {
public:
    int maxSubArray(vector<int> &a) {
        int prevSum = a[0], maxSum = a[0];
        for (int i = 1; i < a.size(); i++) {
            int curSum = max(a[i], a[i] + prevSum);
            maxSum = max(maxSum, curSum);
            prevSum = curSum;
        }
        return maxSum;
    }
};