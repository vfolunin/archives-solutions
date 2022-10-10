class Solution {
public:
    int minimumMountainRemovals(vector<int> &a) {
        vector<int> l(a.size(), 1);
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < i; j++)
                if (a[j] < a[i])
                    l[i] = max(l[i], l[j] + 1);
        
        vector<int> r(a.size(), 1);
        for (int i = a.size() - 1; i >= 0; i--)
            for (int j = a.size() - 1; j > i; j--)
                if (a[j] < a[i])
                    r[i] = max(r[i], r[j] + 1);
        
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            if (l[i] > 1 && r[i] > 1)
                res = max(res, l[i] + r[i] - 1);
        return a.size() - res;
    }
};