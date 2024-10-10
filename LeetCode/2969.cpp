class Solution { 
public:
    int minimumCoins(vector<int> &price) {
        vector<int> cost = price;
        multiset<int> costs = { cost.back() };

        for (int l = (int)cost.size() - 2, r = cost.size() - 1; l >= 0; l--) {
            while (l + l + 2 < r) {
                costs.erase(costs.find(cost[r]));
                r--;
            }
            if (l + l + 2 < cost.size())
                cost[l] += *costs.begin();
            costs.insert(cost[l]);
        }

        return cost[0];
    }
};