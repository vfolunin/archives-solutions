class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        vector<int> res = { 0, (int)-1e9 };
        for (int price : prices) {
            int next0 = max(res[0], res[1] + price - fee);
            int next1 = max(res[1], res[0] - price);
            res = { next0, next1 };
        }
        return res[0];
    }
};