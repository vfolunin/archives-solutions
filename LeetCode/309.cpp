class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> res = { 0, (int)-1e9, 0 };
        for (int price : prices)
            res = { max(res[0], res[2]), max(res[1], res[0] - price), res[1] + price };
        return max(res[0], res[2]);
    }
};