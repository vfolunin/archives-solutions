class Solution {
    int rec(int i, int mask, vector<vector<int>> &cost, vector<vector<int>> &memo) {
        int &res = memo[i][mask];
        if (res != -1)
            return res;
        
        if (!i)
            return res = (mask ? 1e9 : 0);
        
        res = 1e9;
        for (int bit = 0; bit < cost[0].size(); bit++) {
            if (mask & (1 << bit)) {
                res = min({
                    res,
                    rec(i - 1, mask, cost, memo) + cost[i - 1][bit], 
                    rec(i - 1, mask ^ (1 << bit), cost, memo) + cost[i - 1][bit], 
                    rec(i, mask ^ (1 << bit), cost, memo) + cost[i - 1][bit]
                });
            }
        }
        return res;
    }
    
public:
    int connectTwoGroups(vector<vector<int>> &cost) {
        vector<vector<int>> memo(cost.size() + 1, vector<int>(1 << cost[0].size(), -1));
        return rec(cost.size(), (1 << cost[0].size()) - 1, cost, memo);
    }
};