class Solution {
public:
    long long maximumOr(vector<int> &a, int shift) {
        vector<int> l(a.size());
        for (int i = 1; i < a.size(); i++)
            l[i] = l[i - 1] | a[i - 1];

        vector<int> r(a.size());
        for (int i = (int)a.size() - 2; i >= 0; i--)
            r[i] = r[i + 1] | a[i + 1];
        
        long long res = 0;
        for (int i = 0; i < a.size(); i++)
            res = max(res, l[i] | r[i] | ((long long)a[i] << shift));
        return res;
    }
};