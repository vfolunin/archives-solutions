class Solution {
public:
    int countHomogenous(string &s) {
        const long long MOD = 1e9 + 7;
        long long res = 0;
        
        for (int l = 0, r = 0; l < s.size(); l = r) {
            while (r < s.size() && s[l] == s[r])
                r++;
            
            long long size = r - l;
            res = (res + size * (size + 1) / 2) % MOD;
        }
        
        return res;
    }
};