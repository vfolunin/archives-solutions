class Solution {
public:
    int minPathCost(vector<vector<int>> &cost, vector<vector<int>> &weight) {
        int h = cost.size(), w = cost[0].size();
        vector<vector<int>> pathCost = cost;
        
        for (int y = 1; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int minCost = 1e9;
                for (int px = 0; px < w; px++)
                    minCost = min(minCost, pathCost[y - 1][px] + weight[cost[y - 1][px]][x]);
                pathCost[y][x] += minCost;
            }
        }
        
        return *min_element(pathCost.back().begin(), pathCost.back().end());
    }
};