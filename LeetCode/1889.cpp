class Solution {
public:
    int minWastedSpace(vector<int> &a, vector<vector<int>> &b) {
        sort(a.begin(), a.end());
        
        long long res = 1e18;
        
        for (vector<int> &b : b) {
            sort(b.begin(), b.end());
            if (a.back() > b.back())
                continue;
            
            long long l = 0, r = 0, cur = 0;            
            for (int box : b) {
                r = upper_bound(a.begin(), a.end(), box) - a.begin();
                cur += (r - l) * box;
                l = r;
            }            
            res = min(res, cur);
        }
        
        if (res == 1e18)
            return -1;
        
        for (int value : a)
            res -= value;
        const long long MOD = 1e9 + 7;
        return res % MOD;
    }
};