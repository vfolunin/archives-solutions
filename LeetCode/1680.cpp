class Solution {
    string toBin(int n) {
        string res;
        while (n) {
            res += '0' + n % 2;
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
public:
    int concatenatedBinary(int n) {
        const long long MOD = 1e9 + 7;
        long long res = 0;
        
        for (int i = 1; i <= n; i++)
            for (char c : toBin(i))
                res = (res * 2 + c - '0') % MOD;
        
        return res;
    }
};