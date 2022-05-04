class Solution {   
public:
    string longestPalindrome(string s) {
        int bestL = 0, bestLen = 1;
        
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (0 <= l - 1 && r + 1 < s.size() && s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }
            
            if (bestLen < r - l + 1) {
                bestL = l;
                bestLen = r - l + 1;
            }
            
            if (i && s[i - 1] == s[i]) {
                l = i - 1;
                r = i;
                while (0 <= l - 1 && r + 1 < s.size() && s[l - 1] == s[r + 1]) {
                    l--;
                    r++;
                }

                if (bestLen < r - l + 1) {
                    bestL = l;
                    bestLen = r - l + 1;
                }
            }
        }
        
        return s.substr(bestL, bestLen);
    }
};