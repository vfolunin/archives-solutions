class Solution {
public:
    int minPairSum(vector<int> &a) {
        sort(a.begin(), a.end());
        
        int res = 0;
        for (int l = 0, r = a.size() - 1; l < r; l++, r--)
            res = max(res, a[l] + a[r]);
        
        return res;
    }
};