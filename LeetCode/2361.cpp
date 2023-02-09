class Solution {
public:
    vector<long long> minimumCosts(vector<int> &a, vector<int> &b, int bCost) {
        vector<vector<long long>> cost(a.size() + 1, vector<long long>(2));
        cost[0] = { 0, bCost };

        for (int i = 1; i <= a.size(); i++) {
            cost[i][0] = min(cost[i - 1][0] + a[i - 1], cost[i - 1][1] + a[i - 1]);
            cost[i][1] = min(cost[i - 1][0] + bCost + b[i - 1], cost[i - 1][1] + b[i - 1]);
        }

        vector<long long> res(cost.size() - 1);
        for (int i = 0; i < res.size(); i++)
            res[i] = min(cost[i + 1][0], cost[i + 1][1]);
        return res;
    }
};