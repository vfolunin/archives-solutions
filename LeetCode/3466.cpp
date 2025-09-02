class Solution {
public:
    long long maxCoins(vector<int> &lane1, vector<int> &lane2) {
        vector price = { lane1, lane2 };
        vector cost(3, vector<long long>(price[0].size(), -1e18));

        cost[0][0] = price[0][0];
        cost[1][0] = price[1][0];

        for (int x = 1; x < price[0].size(); x++) {
            cost[0][x] = max<long long>(cost[0][x - 1] + price[0][x], price[0][x]);

            for (int swaps = 1; swaps < 3; swaps++)
                cost[swaps][x] = max<long long>(max(cost[swaps][x - 1], cost[swaps - 1][x - 1]) + price[swaps % 2][x], price[swaps % 2][x]);
        }

        long long res = -1e18;
        for (vector<long long> &laneCost : cost)
            res = max(res, *max_element(laneCost.begin(), laneCost.end()));
        return res;
    }
};