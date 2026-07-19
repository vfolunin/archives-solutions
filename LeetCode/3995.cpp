class Solution {
public:
    int minCost(string &a, string &b, vector<vector<string>> &rules, vector<int> &prices) {
        vector<int> cost(a.size() + 1, 1e9);
        cost[0] = 0;

        for (int size = 1; size <= a.size(); size++) {
            if (a[size - 1] == b[size - 1])
                cost[size] = min(cost[size], cost[size - 1]);

            for (int i = 0; i < rules.size(); i++) {
                int ruleSize = rules[i][0].size(), starCount = 0;
                bool ok = ruleSize <= size;
                for (int j = 0; j < ruleSize && ok; j++) {
                    if (rules[i][0][j] == '*')
                        starCount++;
                    else
                        ok &= a[size - ruleSize + j] == rules[i][0][j];
                    ok &= b[size - ruleSize + j] == rules[i][1][j];
                }
                if (ok)
                    cost[size] = min(cost[size], cost[size - ruleSize] + prices[i] + starCount);
            }
        }

        return cost.back() != 1e9 ? cost.back() : -1;
    }
};