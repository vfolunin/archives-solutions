class Solution {
public:
    string longestNiceSubstring(string s) {
        int bestLen = 0, bestL = 0;
        
        for (int l = 0; l < s.size(); l++) {
            int lower = 0, upper = 0;
            for (int r = l; r < s.size(); r++) {
                if (islower(s[r]))
                    lower |= 1 << (s[r] - 'a');
                else
                    upper |= 1 << (s[r] - 'A');
            
                if (lower == upper && bestLen < r - l + 1) {
                    bestLen = r - l + 1;
                    bestL = l;
                }
            }
        }
        
        return s.substr(bestL, bestLen);
    }
};