class Solution {
public:
    int longestSubarray(vector<int> &a) {        
        vector<int> l(a.size());
        for (int i = 1; i < a.size(); i++)
            if (a[i - 1])
                l[i] = l[i - 1] + 1;
        
        vector<int> r(a.size());
        for (int i = (int)a.size() - 2; i >= 0; i--)
            if (a[i + 1])
                r[i] = r[i + 1] + 1;
        
        int res = max(r[0], l[a.size() - 1]);
        for (int i = 1; i + 1 < a.size(); i++)
            res = max(res, l[i] + r[i]);
        return res;
    }
};