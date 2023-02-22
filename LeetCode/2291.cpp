class Solution {
public:
    int maximumProfit(vector<int> &a, vector<int> &b, int budget) {
        vector<int> profit(budget + 1, -1e9);
        profit[0] = 0;

        for (int i = 0; i < a.size(); i++)
            for (int sum = budget; sum >= a[i]; sum--)
                profit[sum] = max(profit[sum], profit[sum - a[i]] + b[i] - a[i]);
        
        return *max_element(profit.begin(), profit.end());
    }
};