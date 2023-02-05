class Solution {
    bool can(vector<int> &a, int robNeed, int valueLimit) {       
        vector<vector<int>> robCount(2, vector<int>(2));
            
        for (int i = 0; i < a.size(); i++) {
            if (a[i] <= valueLimit) {
                robCount[1][0] = max(robCount[0][0], robCount[0][1]);
                robCount[1][1] = 1 + robCount[0][0];
            } else {
                robCount[1][0] = max(robCount[0][0], robCount[0][1]);
                robCount[1][1] = max(robCount[0][0], robCount[0][1]);
            }
            
            if (max(robCount[1][0], robCount[1][1]) >= robNeed)
                return 1;
            
            robCount[0] = robCount[1];
        }
        
        return 0;
    }
    
public:
    int minCapability(vector<int> &a, int robNeed) {
        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, robNeed, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};