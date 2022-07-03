class Solution {
public:
    int waysToSplitArray(vector<int> &a) {
        vector<long long> p(a.size());
        p[0] = a[0];
        for (int i = 1; i < a.size(); i++)
            p[i] = p[i - 1] + a[i];
        
        int res = 0;
        for (int i = 1; i < p.size(); i++)
            res += p[i - 1] >= p.back() - p[i - 1];
        
        return res;
    }
};