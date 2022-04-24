class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for (int l = 0, r = 0; l < prices.size(); l = r + 1) {
            while (l + 1 < prices.size() && prices[l] > prices[l + 1])
                l++;
            r = l + 1;
            while (r + 1 < prices.size() && prices[r] < prices[r + 1])
                r++;
            if (r < prices.size())
                profit += prices[r] - prices[l];
        }
        return profit;
    }
};