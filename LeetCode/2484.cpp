class Solution {
public:
    int countPalindromes(string &s) {
        vector<vector<int>> lDigitCount(s.size(), vector<int>(10));
        vector<vector<int>> lPairCount(s.size(), vector<int>(100));
        
        for (int i = 0; i < s.size(); i++) {
            if (i) {
                lDigitCount[i] = lDigitCount[i - 1];
                lPairCount[i] = lPairCount[i - 1];
            }
            
            for (int prevDigit = 0; prevDigit <= 9; prevDigit++)
                lPairCount[i][prevDigit * 10 + s[i] - '0'] += lDigitCount[i][prevDigit];                
            lDigitCount[i][s[i] - '0']++;
        }
        
        vector<vector<int>> rDigitCount(s.size(), vector<int>(10));
        vector<vector<int>> rPairCount(s.size(), vector<int>(100));
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (i + 1 < s.size()) {
                rDigitCount[i] = rDigitCount[i + 1];
                rPairCount[i] = rPairCount[i + 1];
            }
            
            for (int nextDigit = 0; nextDigit <= 9; nextDigit++)
                rPairCount[i][(s[i] - '0') * 10 + nextDigit] += rDigitCount[i][nextDigit];                
            rDigitCount[i][s[i] - '0']++;
        }
        
        const long long MOD = 1e9 + 7;
        long long res = 0;
        for (int i = 2; i + 2 < s.size(); i++)
            for (int digitA = 0; digitA < 10; digitA++)
                for (int digitB = 0; digitB < 10; digitB++)
                    res = (res + 1LL * lPairCount[i - 1][digitA * 10 + digitB] * rPairCount[i + 1][digitB * 10 + digitA]) % MOD;
        return res;
    }
};