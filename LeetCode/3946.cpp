class Solution {
public:
    int maximumSaleItems(vector<vector<int>> &items, int budget) {
        vector<int> maxProfit(budget + 1);

        for (int i = 0; i < items.size(); i++) {
            int price = items[i][1], profit = 0;
            for (int j = 0; j < items.size(); j++)
                profit += items[j][0] % items[i][0] == 0;
            
            vector<int> nextMaxProfit = maxProfit;
            for (int cost = budget; cost >= price; cost--)
                nextMaxProfit[cost] = max(nextMaxProfit[cost], nextMaxProfit[cost - price] + profit);
            for (int cost = price; cost <= budget; cost++)
                nextMaxProfit[cost] = max(nextMaxProfit[cost], nextMaxProfit[cost - price] + 1);
            maxProfit.swap(nextMaxProfit);
        }

        return *max_element(maxProfit.begin(), maxProfit.end());
    }
};