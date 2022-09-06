class Solution {
    int getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    int waysToSplit(vector<int> &p) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        long long res = 0;
        
        for (int i = 0; i + 2 < p.size(); i++) {
            int l = i;
            int r = p.size() - 1;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (getSum(p, 0, i) > getSum(p, i + 1, m))
                    l = m;
                else
                    r = m;
            }
            int lower = r;
            
            l = i;
            r = p.size() - 1;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (getSum(p, i + 1, m) <= getSum(p, m + 1, p.size() - 1))
                    l = m;
                else
                    r = m;
            }
            int upper = l;
            
            res += max(0, upper - lower + 1);
        }
        
        const long long MOD = 1e9 + 7;
        return res % MOD;
    }
};