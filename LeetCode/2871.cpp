class Solution {
public:
    int maxSubarrays(vector<int> &a) {
        int totalAnd = a[0];
        for (int value : a)
            totalAnd &= value;
        
        int curAnd = 0, res = 0;
        for (int value : a) {
            if (curAnd) {
                curAnd &= value;
            } else {
                curAnd = value;
                res++;
            }
        }
        res -= curAnd != totalAnd;
        return res;
    }
};