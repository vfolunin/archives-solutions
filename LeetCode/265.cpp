class Solution {
public:
    int minCostII(vector<vector<int>> &price) {
        vector<vector<int>> cost(price.size(), vector<int>(price[0].size(), 1e9));
        cost[0] = price[0];

        for (int i = 1; i < cost.size(); i++)
            for (int last = 0; last < price[0].size(); last++)
                for (int prev = 0; prev < price[0].size(); prev++)
                    if (prev != last)
                        cost[i][last] = min(cost[i][last], cost[i - 1][prev] + price[i][last]);
        
        return *min_element(cost.back().begin(), cost.back().end());
    }
};