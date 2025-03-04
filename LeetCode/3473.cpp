class Solution {
    int getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }

public:
    int maxSum(vector<int> &p, int targetPartCount, int minSize) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<vector<int>> maxSumTo(p.size(), vector<int>(targetPartCount + 1, -2e9));
        vector<vector<int>> maxSum(p.size(), vector<int>(targetPartCount + 1, -2e9));

        for (int i = minSize - 1; i < p.size(); i++) {
            maxSumTo[i][1] = getSum(p, i - minSize + 1, i);
            if (i >= minSize)
                maxSumTo[i][1] = max(maxSumTo[i][1], maxSumTo[i - 1][1] + getSum(p, i, i));

            for (int partCount = 2; partCount <= targetPartCount; partCount++) {
                if (i >= partCount * minSize - 1) {
                    maxSumTo[i][partCount] = max(
                        maxSumTo[i - 1][partCount] + getSum(p, i, i),
                        maxSum[i - minSize][partCount - 1] + getSum(p, i - minSize + 1, i)
                    );
                }
            }

            for (int partCount = 1; partCount <= targetPartCount; partCount++) {
                if (i)
                    maxSum[i][partCount] = max(maxSum[i][partCount], maxSum[i - 1][partCount]);
                maxSum[i][partCount] = max(maxSum[i][partCount], maxSumTo[i][partCount]);
            }
        }

        return maxSum.back().back();
    }
};