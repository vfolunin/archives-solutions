class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> cost(n + 1, vector<int>(n + 1));
        for (int len = 2; len <= n; len++) {
            for (int l = 1, r = len; r <= n; l++, r++) {
                cost[l][r] = min(l + cost[l + 1][r], r + cost[l][r - 1]);
                for (int m = l + 1; m < r; m++)
                    cost[l][r] = min(cost[l][r], m + max(cost[l][m - 1], cost[m + 1][r]));
            }
        }
        return cost[1][n];
    }
};