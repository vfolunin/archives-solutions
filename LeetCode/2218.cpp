class Solution {
public:
    int maxValueOfCoins(vector<vector<int>> &a, int limit) {
        vector<vector<int>> res(a.size(), vector<int>(limit + 1, -1e9));
        
        res[0][0] = 0;
        int sum = 0;
        
        for (int take = 1; take <= a[0].size() && take <= limit; take++) {
            sum += a[0][take - 1];
            res[0][take] = sum;
        }
        
        for (int i = 1; i < a.size(); i++) {
            for (int take = 0; take <= limit; take++) {
                res[i][take] = res[i - 1][take];
                int sum = 0;
                
                for (int curTake = 1; curTake <= a[i].size() && curTake <= take; curTake++) {
                    sum += a[i][curTake - 1];
                    res[i][take] = max(res[i][take], res[i - 1][take - curTake] + sum);
                }
            }
        }
        
        return res[a.size() - 1][limit];
    }
};