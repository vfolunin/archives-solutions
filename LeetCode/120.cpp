class Solution {
public:
    int minimumTotal(vector<vector<int>> &a) {
        vector<vector<int>> cost(a.size());
        for (int i = 0; i < a.size(); i++) {
            cost[i].resize(i + 1);
            cost[i][0] = a[i][0] + (i ? cost[i - 1][0] : 0);
            for (int j = 1; j < i; j++)
                cost[i][j] = a[i][j] + min(cost[i - 1][j - 1], cost[i - 1][j]);
            cost[i][i] = a[i][i] + (i ? cost[i - 1][i - 1] : 0);
        }
        return *min_element(cost.back().begin(), cost.back().end());
    }
};