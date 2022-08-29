class Solution {
public:
    int longestMountain(vector<int> &a) {
        vector<int> l(a.size());
        for (int i = 1; i < a.size(); i++)
            if (a[i - 1] < a[i])
                l[i] = l[i - 1] + 1;
        
        vector<int> r(a.size());
        for (int i = a.size() - 2; i >= 0; i--)
            if (a[i] > a[i + 1])
                r[i] = r[i + 1] + 1;
        
        int res = 0;
        for (int i = 1; i + 1 < a.size(); i++)
            if (l[i] && r[i])
                res = max(res, l[i] + 1 + r[i]);
        return res;
    }
};