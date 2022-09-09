class Solution {
public:
    int kConcatenationMaxSum(vector<int> &a, long long k) {
        vector<long long> r(a.begin(), a.end());
        partial_sum(r.begin(), r.end(), r.begin());
        
        vector<long long> l(a.begin(), a.end());
        partial_sum(l.rbegin(), l.rend(), l.rbegin());
        
        long long res = 0;
        
        long long minPrefixSum = 0;
        for (int i = 0; i < r.size(); i++) {
            res = max(res, r[i] - minPrefixSum);
            minPrefixSum = min(minPrefixSum, r[i]);
        }            
        
        res = max(res, k * r.back());
        res = max(res, (k - 1) * r.back() + *max_element(l.begin(), l.end()));
        res = max(res, (k - 1) * r.back() + *max_element(r.begin(), r.end()));
        
        if (k >= 2) {
            res = max(res, (k - 2) * r.back() + *max_element(l.begin(), l.end()) + *max_element(r.begin(), r.end()));
            res = max(res, *max_element(l.begin(), l.end()) + *max_element(r.begin(), r.end()));
        }
        
        const long long MOD = 1e9 + 7;
        return res % MOD;
    }
};