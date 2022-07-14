class Solution {
    int findDistance(vector<int> &a, int x) {
        auto r = upper_bound(a.begin(), a.end(), x);
        if (r == a.end())
            return x - *--r;
        if (r == a.begin())
            return *r - x;
        
        auto l = prev(r);
        return min(x - *l, *r - x);
    }
    
public:
    int findRadius(vector<int> &a, vector<int> &b) {
        sort(b.begin(), b.end());
        
        int res = 0;
        for (int x : a)
            res = max(res, findDistance(b, x));
        
        return res;
    }
};