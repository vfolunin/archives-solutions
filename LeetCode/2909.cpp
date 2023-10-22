class Solution {
public:
    int minimumSum(vector<int> &a) {
        vector<int> l = a;
        for (int i = 1; i < a.size(); i++)
            l[i] = min(l[i], l[i - 1]);
        
        vector<int> r = a;
        for (int i = (int)a.size() - 2; i >= 0; i--)
            r[i] = min(r[i], r[i + 1]);
        
        int res = 1e9;
        
        for (int i = 1; i + 1 < a.size(); i++)
            if (l[i - 1] < a[i] && a[i] > r[i + 1])
                res = min(res, l[i - 1] + a[i] + r[i + 1]);
        
        return res != 1e9 ? res : -1;
    }
};