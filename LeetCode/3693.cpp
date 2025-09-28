class Solution {
public:
    int climbStairs(int size, vector<int> &price) {
        vector<int> cost(size + 1, 1e9);
        cost[0] = 0;

        for (int i = 0; i < size; i++)
            for (int j = i + 1; j <= i + 3 && j < cost.size(); j++)
                cost[j] = min(cost[j], cost[i] + price[j - 1] + (j - i) * (j - i));
        
        return cost.back();
    }
};