class Solution {
    long long getSum(vector<long long> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    int maxFrequency(vector<int> &a, int k) {
        vector<long long> p(a.begin(), a.end());
        sort(p.rbegin(), p.rend());
        partial_sum(p.begin(), p.end(), p.begin());
        
        int res = 0;
        
        for (int i = 0; i < a.size(); i++) {
            int l = i, r = a.size();
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if ((m - i + 1) * getSum(p, i, i) - getSum(p, i, m) <= k)
                    l = m;
                else
                    r = m;
            }
            res = max(res, l - i + 1);
        }
        
        return res;
    }
};