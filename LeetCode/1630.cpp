class Solution {
    bool can(vector<int> a, int l, int r) {
        if (r - l <= 1)
            return 1;
        
        sort(a.begin() + l, a.begin() + r + 1);
        
        int dist = a[l + 1] - a[l];
        for (int i = l + 1; i < r; i++)
            if (a[i + 1] - a[i] != dist)
                return 0;
        
        return 1;
    }
    
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &a, vector<int> &l, vector<int> &r) {
        vector<bool> res(l.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = can(a, l[i], r[i]);
        return res;
    }
};