class Solution {
public:
    int findTheDistanceValue(vector<int> &a, vector<int> &b, int d) {
        sort(b.begin(), b.end());
        int res = 0;
        
        for (int value : a) {
            auto bl = lower_bound(b.begin(), b.end(), value - d);
            auto br = upper_bound(b.begin(), b.end(), value + d);
            res += bl == br;
        }
        
        return res;
    }
};