class Solution {
    int doRob0(vector<int> &cost) {
        vector<int> bonus(cost.size());
        bonus[0] = cost[0];
        bonus[1] = max(cost[0], cost[1]);        
        for (int i = 2; i + 1 < cost.size(); i++)
            bonus[i] = max(bonus[i - 1], cost[i] + bonus[i - 2]);
        return bonus[bonus.size() - 2];
    }
    
    int doNotRob0(vector<int> &cost) {
        vector<int> bonus(cost.size());
        bonus[1] = cost[1];
        for (int i = 2; i < cost.size(); i++)
            bonus[i] = max(bonus[i - 1], cost[i] + bonus[i - 2]);
        return bonus.back();
    }
    
public:
    int rob(vector<int> &cost) {
        if (cost.size() == 1)
            return cost[0];
        return max(doRob0(cost), doNotRob0(cost));
    }
};