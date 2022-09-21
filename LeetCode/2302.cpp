class Solution {
    long long getSum(vector<long long> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    long long countSubarrays(vector<int> &a, long long limit) {
        vector<long long> p = { a.begin(), a.end() };
        partial_sum(p.begin(), p.end(), p.begin());
        
        long long res = 0;
        for (int i = 0; i < a.size(); i++) {
            int l = i - 1, r = a.size();
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (getSum(p, i, m) * (m - i + 1) < limit)
                    l = m;
                else
                    r = m;
            }
            res += l - i + 1;
        }
        
        return res;
    }
};