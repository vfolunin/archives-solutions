class Solution {
public:
    int removeBoxes(vector<int> &a) {
        vector<vector<vector<int>>> cost(a.size(), vector<vector<int>>(a.size(), vector<int>(a.size())));
        for (int i = 0; i < a.size(); i++)
            for (int leftBoxes = 0; leftBoxes < a.size(); leftBoxes++)
                cost[i][i][leftBoxes] = (leftBoxes + 1) * (leftBoxes + 1);
        
        for (int len = 2; len <= a.size(); len++) {
            for (int l = 0, r = len - 1; r < a.size(); l++, r++) {
                for (int leftBoxes = 0; leftBoxes <= l; leftBoxes++) {
                    cost[l][r][leftBoxes] = (leftBoxes + 1) * (leftBoxes + 1) + cost[l + 1][r][0];
                    
                    for (int m = l + 1; m <= r; m++)
                        if (a[l] == a[m])
                            cost[l][r][leftBoxes] = max(cost[l][r][leftBoxes], cost[l + 1][m - 1][0] + cost[m][r][leftBoxes + 1]);
                }
            }
        }
        
        return cost[0][a.size() - 1][0];
    }
};