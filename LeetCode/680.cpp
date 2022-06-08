class Solution {
    bool isPalindrome(const string &s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            if (s[l] != s[r])
                return 0;
        return 1;
    }
    
public:
    bool validPalindrome(string s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            if (s[l] != s[r])
                return isPalindrome(s.substr(0, l) + s.substr(l + 1)) ||
                       isPalindrome(s.substr(0, r) + s.substr(r + 1));
        return 1;
    }
};