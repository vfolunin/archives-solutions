class Solution {    
public:
    int paintWalls(vector<int> &price, vector<int> &time) {
        for (int &t : time)
            t++;
        
        vector<int> minCost(price.size() * 2 + 1, 1e9);
        minCost[0] = 0;
        
        for (int i = 0; i < price.size(); i++)
            for (int j = minCost.size() - 1; j >= time[i]; j--)
                minCost[j] = min(minCost[j], minCost[j - time[i]] + price[i]);
        
        return *min_element(minCost.begin() + price.size(), minCost.end());
    }
};