class Solution {
public:
    long long maxSumTrionic(vector<int> &a) {
        vector<vector<long long>> maxSum(a.size(), vector<long long>(4, -1e18));
        maxSum[0][0] = a[0];

        for (int i = 1; i < a.size(); i++) {
            maxSum[i][0] = a[i];
            if (a[i - 1] < a[i]) {
                maxSum[i][1] = max(maxSum[i - 1][0], maxSum[i - 1][1]) + a[i];
                maxSum[i][3] = max(maxSum[i - 1][2], maxSum[i - 1][3]) + a[i];
            } else if (a[i - 1] > a[i]) {
                maxSum[i][2] = max(maxSum[i - 1][1], maxSum[i - 1][2]) + a[i];
            }
        }

        long long res = -1e18;
        for (int i = 0; i < a.size(); i++)
            res = max(res, maxSum[i][3]);
        return res;
    }
};