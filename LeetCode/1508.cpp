class Solution {
public:
    int rangeSum(vector<int> &p, int n, int from, int to) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<int> sums;
        for (int l = 0; l < p.size(); l++)
            for (int r = l; r < p.size(); r++)
                sums.push_back(p[r] - (l ? p[l - 1] : 0));
        sort(sums.begin(), sums.end());
        
        long long res = 0;
        for (int i = from - 1; i < to; i++)
            res += sums[i];
        
        long long mod = 1e9 + 7;
        return res % mod;
    }
};