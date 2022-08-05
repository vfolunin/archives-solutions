class Solution {
public:
    int minDifference(vector<int> &a) {
        if (a.size() <= 4)
            return 0;
        
        sort(a.begin(), a.end());
        
        int res = 2e9;
        for (int l = 0, r = a.size() - 4; r < a.size(); l++, r++)
            res = min(res, a[r] - a[l]);
        return res;
    }
};