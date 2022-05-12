class Solution {
public:
    int numSub(string s) {
        long long res = 0, MOD = 1e9 + 7;
        
        long long row = 0;
        for (char c : s) {
            if (c == '1') {
                row++;
            } else {
                res += row * (row + 1) / 2;
                row = 0;
            }
        }
        res += row * (row + 1) / 2;
        
        return res % MOD;
    }
};