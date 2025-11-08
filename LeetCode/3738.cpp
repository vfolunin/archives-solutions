class Solution {
public:
    int longestSubarray(vector<int> &a) {
        vector<int> l(a.size(), 1);
        for (int i = 1; i < a.size(); i++)
            if (a[i - 1] <= a[i])
                l[i] += l[i - 1];

        vector<int> r(a.size(), 1);
        for (int i = (int)a.size() - 2; i >= 0; i--)
            if (a[i] <= a[i + 1])
                r[i] += r[i + 1];
    
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            res = max({ res, l[i], r[i] });
            if (i)
                res = max(res, l[i - 1] + 1);
            if (i + 1 < a.size())
                res = max(res, 1 + r[i + 1]);
            if (i && i + 1 < a.size() && a[i - 1] <= a[i + 1])
                res = max(res, l[i - 1] + 1 + r[i + 1]);
        }
        return res;
    }
};