class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice = prices[0], maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};