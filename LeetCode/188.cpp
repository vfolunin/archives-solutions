class Solution {
public:
    int maxProfit(int opLimit, vector<int> &prices) {
        int res = 0;
        
        if (opLimit >= prices.size() / 2) {
            for (int i = 1; i < prices.size(); i++)
                if (prices[i] > prices[i - 1])
                    res += prices[i] - prices[i - 1];
        } else {
            vector<vector<int>> profit(opLimit + 1, vector<int>(2, -1e9));
            profit[0][0] = 0;
        
            for (int i = 0; i < prices.size(); i++) {
                for (int ops = opLimit; ops >= 1; ops--) {
                    profit[ops][0] = max(profit[ops][0], profit[ops][1] + prices[i]);
                    profit[ops][1] = max(profit[ops][1], profit[ops - 1][0] - prices[i]);
                    res = max(res, profit[ops][0]);
                }
            }
        }
        
        return res;
    }
};