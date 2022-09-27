class Solution {
public:
    int minMovesToMakePalindrome(string &s) {
        if (s.size() <= 2)
            return 0;
        
        int res = 1e9, resL, resR;
        
        for (char c = 'a'; c <= 'z'; c++) {
            int l = s.find(c);
            int r = s.rfind(c);
            
            if (l != -1 && l != r && res > l + s.size() - 1 - r) {
                res = l + s.size() - 1 - r;
                resL = l;
                resR = r;
            }
        }
        
        s.erase(s.begin() + resR);
        s.erase(s.begin() + resL);
        return res + minMovesToMakePalindrome(s);
    }
};