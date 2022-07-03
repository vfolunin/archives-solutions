class Solution {
public:
    int countTexts(string &s) {
        const long long MOD = 1e9 + 7;
        
        vector<long long> a = { 1, 1, 2 };
        for (int i = a.size(); i <= s.size(); i++)
            a.push_back((a[i - 3] + a[i - 2] + a[i - 1]) % MOD);
        
        vector<long long> b = { 1, 1, 2, 4 };
        for (int i = b.size(); i <= s.size(); i++)
            b.push_back((b[i - 4] + b[i - 3] + b[i - 2] + b[i - 1]) % MOD);
        
        int row = 1, res = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                row++;
            } else {
                res = res * (s[i - 1] != '7' && s[i - 1] != '9' ? a[row] : b[row]) % MOD;
                row = 1;
            }
        }
        res = res * (s.back() != '7' && s.back() != '9' ? a[row] : b[row]) % MOD;
        
        return res;
    }
};