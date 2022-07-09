class Solution {
public:
    int subarraysDivByK(vector<int> &a, int mod) {
        int res = 0, remainder = 0;
        
        vector<int> seen(mod);
        seen[remainder]++;
        
        for (int value : a) {
            remainder = ((remainder + value) % mod + mod) % mod;
            res += seen[remainder];
            seen[remainder]++;
        }
        
        return res;
    }
};