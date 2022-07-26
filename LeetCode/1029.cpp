class Solution {
public:
    int twoCitySchedCost(vector<vector<int>> &cost) {
        int n = cost.size() / 2;
        
        vector<vector<int>> res(n + 1, vector<int>(n + 1, 1e9));
        res[0][0] = 0;
        
        for (int a = 0; a <= n; a++) {
            for (int b = 0; b <= n; b++) {
                if (a)
                    res[a][b] = min(res[a][b], res[a - 1][b] + cost[a + b - 1][0]);
                if (b)
                    res[a][b] = min(res[a][b], res[a][b - 1] + cost[a + b - 1][1]);
            }
        }
        
        return res[n][n];
    }
};