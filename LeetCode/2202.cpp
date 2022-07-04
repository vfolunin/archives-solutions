class Solution {
public:
    int maximumTop(vector<int> &a, int k) {
        if (k == 0)
            return a[0];
        
        if (k == 1)
            return a.size() >= 2 ? a[1] : -1;
        
        if (a.size() == 1)
            return k % 2 == 0 ? a[0] : -1;
        
        int res = *max_element(a.begin(), min(a.begin() + k - 1, a.end()));
        if (k < a.size())
            res = max(res, a[k]);
        return res;
    }
};