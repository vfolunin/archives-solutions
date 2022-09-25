class Solution {
public:
    vector<int> goodIndices(vector<int> &a, int k) {
        vector<int> l(a.size(), 1);
        for (int i = 1; i < a.size(); i++)
            if (a[i - 1] >= a[i])
                l[i] = l[i - 1] + 1;
        
        vector<int> r(a.size(), 1);
        for (int i = a.size() - 2; i >= 0; i--)
            if (a[i] <= a[i + 1])
                r[i] = r[i + 1] + 1;
        
        vector<int> res;
        for (int i = k; i + k < a.size(); i++)
            if (l[i - 1] >= k && r[i + 1] >= k)
                res.push_back(i);
        return res;
    }
};