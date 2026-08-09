class Solution {
public:
    double minPrice(vector<int> &prices, vector<int> &discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        double res = 0;
        for (int i = 0; i < prices.size(); i++)
            res += prices[i] * (i < discounts.size() ? 100 - discounts[i] : 100) / 100.0;
        return res;
    }
};