class Solution {
    int maxProfit(vector<int> &a) {
        vector<vector<int>> profit(a.size(), vector<int>(a.size() / 3 + 1));
        profit[0][1] = a[0];
        profit[1][1] = max(a[0], a[1]);
        
        for (int i = 2; i < a.size(); i++)
            for (int k = 1; k * 3 <= a.size(); k++)
                profit[i][k] = max(profit[i - 1][k], profit[i - 2][k - 1] + a[i]);
        
        return profit[a.size() - 2][a.size() / 3];
    }
    
public:
    int maxSizeSlices(vector<int> &a) {
        int res = 0;
        for (int i = 0; i < 3; i++) {
            res = max(res, maxProfit(a));
            rotate(a.begin(), a.begin() + 1, a.end());
        }
        return res;
    }
};