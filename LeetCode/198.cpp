class Solution {
public:
    int rob(vector<int> &a) {
        vector<int> cost(a.size() + 1);
        cost[1] = a[0];
        for (int i = 2; i <= a.size(); i++)
            cost[i] = max(cost[i - 1], a[i - 1] + cost[i - 2]);
        return cost.back();
    }
};