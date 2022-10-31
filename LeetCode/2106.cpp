class Solution {
    int getSum(vector<int> &p, int l, int r) {
        l = max(l, 0);
        r = min<int>(r, p.size() - 1);
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int start, int stepCount) {
        vector<int> p((int)2e5 + 1);
        for (vector<int> &fruit : fruits)
            p[fruit[0]] += fruit[1];
        partial_sum(p.begin(), p.end(), p.begin());
        
        int res = 0;
        
        for (int leftStepCount = 0; leftStepCount <= stepCount; leftStepCount++) {
            int l = start - leftStepCount;
            int r = max(start, l + (stepCount - leftStepCount));
            res = max(res, getSum(p, l, r));
        }
        
        for (int rightStepCount = 0; rightStepCount <= stepCount; rightStepCount++) {
            int r = start + rightStepCount;
            int l = min(start, r - (stepCount - rightStepCount));
            res = max(res, getSum(p, l, r));
        }
        
        return res;
    }
};