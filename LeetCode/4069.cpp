class Solution {
public:
    int maxProfit(vector<int> &price, int gap, vector<int> &penalty) {
        vector<int> maxProfit(price.size() + 1);
        for (int sellDay = 1; sellDay <= price.size(); sellDay++) {
            maxProfit[sellDay] = maxProfit[sellDay - 1];
            for (int buyDay = 1; buyDay <= sellDay; buyDay++) {
                int profit = price[sellDay - 1] - price[buyDay - 1] - penalty[sellDay - buyDay];
                int prevSellDay = buyDay - gap - 1;
                if (prevSellDay >= 0)
                    profit += maxProfit[prevSellDay];
                maxProfit[sellDay] = max(maxProfit[sellDay], profit);
            }
        }
        return maxProfit.back();
    }
};