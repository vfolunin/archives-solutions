class Solution {
public:
    int maximumSum(vector<int> &a) {
        if (a.size() == 1)
            return a[0];
        
        vector<int> l = a;
        for (int i = 1; i < a.size(); i++)
            l[i] = max(l[i], l[i] + l[i - 1]);
        
        vector<int> r = a;
        for (int i = a.size() - 2; i >= 0; i--)
            r[i] = max(r[i], r[i] + r[i + 1]);
        
        int res = *max_element(l.begin(), l.end());
        res = max(res, r[1]);
        for (int i = 1; i + 1 < a.size(); i++)
            res = max(res, l[i - 1] + r[i + 1]);
        return res;
    }
};