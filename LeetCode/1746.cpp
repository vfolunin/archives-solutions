class Solution {
public:
    int maxSumAfterOperation(vector<int> &a) {
        vector<vector<int>> maxSum(a.size(), vector<int>(2));
        maxSum[0][0] = a[0];
        maxSum[0][1] = a[0] * a[0];

        int res = maxSum[0][1];

        for (int i = 1; i < a.size(); i++) {
            maxSum[i][0] = max(maxSum[i - 1][0] + a[i], a[i]);
            maxSum[i][1] = max({ maxSum[i - 1][1] + a[i], maxSum[i - 1][0] + a[i] * a[i], a[i] * a[i] });

            res = max(res, maxSum[i][1]);
        }

        return res;
    }
};