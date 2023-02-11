class Solution {
    int rec(int i, int weightLimit, int couponLimit, vector<int> &weight, vector<int> &cost, vector<vector<vector<int>>> &memo) {
        if (i == weight.size())
            return 0;

        int &res = memo[i][weightLimit][couponLimit];
        if (res != -1)
            return res;
        
        res = rec(i + 1, weightLimit, couponLimit, weight, cost, memo);
        if (weightLimit >= weight[i])
            res = max(res, rec(i + 1, weightLimit - weight[i], couponLimit, weight, cost, memo) + cost[i]);
        if (weightLimit >= weight[i] / 2 && couponLimit)
            res = max(res, rec(i + 1, weightLimit - weight[i] / 2, couponLimit - 1, weight, cost, memo) + cost[i]);

        return res;
    }

public:
    int maxTastiness(vector<int> &weight, vector<int> &cost, int weightLimit, int couponLimit) {
        vector<vector<vector<int>>> memo(weight.size(), vector<vector<int>>(weightLimit + 1, vector<int>(couponLimit + 1, -1)));
        return rec(0, weightLimit, couponLimit, weight, cost, memo);
    }
};