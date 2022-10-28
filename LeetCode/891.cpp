class Solution {
public:
    int sumSubseqWidths(vector<int> &a) {
        sort(a.begin(), a.end());
        
        const long long MOD = 1e9 + 7;
        
        vector<long long> p(a.size());
        p[0] = 1;
        for (int i = 1; i < p.size(); i++)
            p[i] = p[i - 1] * 2 % MOD;
        
        long long res = 0;
        for (int i = 0, j = a.size() - 1; i < a.size(); i++, j--)
            res = (res + a[i] * (p[i] - p[j])) % MOD;
        return res;
    }
};