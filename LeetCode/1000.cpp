class Solution {
    int getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    int mergeStones(vector<int> &p, int k) {
        if ((p.size() - 1) % (k - 1))
            return -1;

        partial_sum(p.begin(), p.end(), p.begin());

        vector<vector<vector<int>>> cost(p.size(), vector<vector<int>>(p.size(), vector<int>(k + 1, 1e9)));
        
        for (int i = 0; i < p.size(); i++)
            cost[i][i][1] = 0;
        
        for (int len = 2; len <= p.size(); len++) {
            for (int l = 0, r = len - 1; r < p.size(); l++, r++) {
                for (int piles = 2; piles <= k; piles++)
                    for (int m = l; m < r; m++)
                        cost[l][r][piles] = min(cost[l][r][piles], cost[l][m][piles - 1] + cost[m + 1][r][1]);
                
                cost[l][r][1] = min(cost[l][r][1], cost[l][r][k] + getSum(p, l, r));
            }
        }
        
        return cost[0][p.size() - 1][1];
    }
};