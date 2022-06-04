class Solution {
public:
    int minimumDifference(vector<int> &a, int k) {
        sort(a.begin(), a.end());
        
        int res = 1e9;
        for (int l = 0, r = k - 1; r < a.size(); l++, r++)
            res = min(res, a[r] - a[l]);
        
        return res;
    }
};