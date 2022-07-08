class Solution {
public:
    int minCost(vector<int> &houseColor, vector<vector<int>> &colorCost, int houseCount, int colorCount, int target) {
        vector<vector<vector<int>>> cost(houseCount, vector<vector<int>>(colorCount + 1, vector<int>(target + 1, 1e9)));
        
        if (houseColor[0]) {
            cost[0][houseColor[0]][1] = 0;
        } else {
            for (int color = 1; color <= colorCount; color++)
                cost[0][color][1] = colorCost[0][color - 1];
        }
        
        for (int house = 1; house < houseCount; house++) {
            for (int color = 1; color <= colorCount; color++) {
                if (houseColor[house] && houseColor[house] != color)
                    continue;
                
                for (int groups = 1; groups <= target; groups++) {
                    for (int prevColor = 1; prevColor <= colorCount; prevColor++) {
                        int prevGroups = groups - (color != prevColor);
                        if (!prevGroups || cost[house - 1][prevColor][prevGroups] == 1e9)
                            continue;
                        
                        int price = (houseColor[house] ? 0 : colorCost[house][color - 1]);
                        cost[house][color][groups] = min(cost[house][color][groups], cost[house - 1][prevColor][prevGroups] + price);
                    }
                }
            }
        }
        
        int res = 1e9;
        for (int color = 1; color <= colorCount; color++)
            res = min(res, cost[houseCount - 1][color][target]);
        
        return res != 1e9 ? res : -1;
    }
};