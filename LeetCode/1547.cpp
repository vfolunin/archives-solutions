class Solution {
public:
    int minCost(int width, vector<int> &a) {
        a.push_back(0);
        a.push_back(width);
        sort(a.begin(), a.end());
        
        vector<vector<int>> cost(a.size(), vector<int>(a.size()));
        
        for (int len = 3; len <= a.size(); len++) {
            for (int l = 0, r = len - 1; r < a.size(); l++, r++) {
                cost[l][r] = 1e9;
                for (int m = l + 1; m < r; m++)
                    cost[l][r] = min(cost[l][r], cost[l][m] + cost[m][r] + a[r] - a[l]);
            }
        }
        
        return cost[0][a.size() - 1];
    }
};