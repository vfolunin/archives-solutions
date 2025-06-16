class Solution {
public:
    long long maximumProfit(vector<int> &a, int opLimit) {
        vector<vector<long long>> res(2, vector<long long>(a.size()));

        for (int ops = 1; ops <= opLimit; ops++) {
            res[0] = res[1];
            fill(res[1].begin(), res[1].end(), 0);

            long long buy = -a[0];
            long long sell = a[0];

            for (int i = 1; i < a.size(); i++) {
                res[1][i] = max({ res[1][i - 1], buy + a[i], sell - a[i] });
                
                buy = max(buy, res[0][i - 1] - a[i]);
                sell = max(sell, res[0][i - 1] + a[i]);
            }
        }

        return res[1].back();
    }
};