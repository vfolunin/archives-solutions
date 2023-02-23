class Solution {
public:
    int minimumMoves(vector<int> &a) {
        vector<vector<int>> cost(a.size(), vector<int>(a.size(), 1e9));

        for (int i = 0; i < a.size(); i++)
            cost[i][i] = 1;
        
        for (int l = 0, r = 1; r < a.size(); l++, r++)
            cost[l][r] = (a[l] == a[r] ? 1 : 2);

        for (int len = 3; len <= a.size(); len++) {
            for (int l = 0, r = len - 1; r < a.size(); l++, r++) {
                if (a[l] == a[r])
                    cost[l][r] = cost[l + 1][r - 1];
                for (int m = l; m < r; m++)
                    cost[l][r] = min(cost[l][r], cost[l][m] + cost[m + 1][r]);
            }
        }

        return cost[0][a.size() - 1];
    }
};