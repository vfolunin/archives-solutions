class Solution {    
public:
    int paintWalls(vector<int> &price, vector<int> &time) {
        int totalTime = 0;
        for (int &t : time) {
            t++;
            totalTime += t;
        }
        
        vector<int> minCost(totalTime + 1, 1e9);
        minCost[0] = 0;
        
        for (int i = 0; i < price.size(); i++)
            for (int j = minCost.size() - 1; j >= time[i]; j--)
                minCost[j] = min(minCost[j], minCost[j - time[i]] + price[i]);
        
        return *min_element(minCost.begin() + price.size(), minCost.end());
    }
};