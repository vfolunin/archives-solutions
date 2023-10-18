class Solution {
public:
    int maxProfit(vector<int> &prices, vector<int> &profits) {
        int res = -1;

        for (int i = 1; i + 1 < prices.size(); i++) {
            int lMax = 0;
            for (int j = 0; j < i; j++)
                if (prices[j] < prices[i])
                    lMax = max(lMax, profits[j]);
            
            int rMax = 0;
            for (int j = i + 1; j < prices.size(); j++)
                if (prices[i] < prices[j])
                    rMax = max(rMax, profits[j]);
            
            if (lMax && rMax)
                res = max(res, lMax + profits[i] + rMax);
        }
        
        return res;
    }
};