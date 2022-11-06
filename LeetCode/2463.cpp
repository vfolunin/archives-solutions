class Solution {
public:
    long long minimumTotalDistance(vector<int> &rPos, vector<vector<int>> &fPos) {
        sort(rPos.begin(), rPos.end());
        sort(fPos.begin(), fPos.end());
        
        vector<vector<long long>> cost(rPos.size() + 1, vector<long long>(fPos.size() + 1, 1e18));
        fill(cost[0].begin(), cost[0].end(), 0);
        
        for (int ri = 1; ri <= rPos.size(); ri++) {
            for (int fi = 1; fi <= fPos.size(); fi++) {
                cost[ri][fi] = cost[ri][fi - 1];
                
                long long lastCost = 0;
                for (int k = 1; k <= ri && k <= fPos[fi - 1][1]; k++) {
                    lastCost += abs(rPos[ri - k] - fPos[fi - 1][0]);
                    cost[ri][fi] = min(cost[ri][fi], cost[ri - k][fi - 1] + lastCost);
                }
            }
        }
        
        return cost[rPos.size()][fPos.size()];
    }
};