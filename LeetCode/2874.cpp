class Solution {
public:
    long long maximumTripletValue(vector<int> &a) {
        vector<int> l = a;
        for (int i = 1; i < a.size(); i++)
            l[i] = max(l[i - 1], l[i]);
        
        vector<int> r = a;
        for (int i = a.size() - 2; i >= 0; i--)
            r[i] = max(r[i], r[i + 1]);
        
        long long res = 0;
        for (int i = 1; i + 1 < a.size(); i++)
            res = max(res, 1LL * (l[i - 1] - a[i]) * r[i + 1]);
        return res;
    }
};