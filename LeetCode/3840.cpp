class Solution {
public:
    long long rob(vector<int> &amount, vector<int> &color) {
        vector<long long> maxSum(amount.size() + 1);
        maxSum[1] = amount[0];

        for (int size = 2; size <= amount.size(); size++) {
            maxSum[size] = max(maxSum[size - 1], maxSum[size - 2] + amount[size - 1]);
            if (color[size - 2] != color[size - 1])
                maxSum[size] = max(maxSum[size], maxSum[size - 1] + amount[size - 1]);
        }
        
        return maxSum.back();
    }
};