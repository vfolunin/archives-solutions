class Solution {
    bool isPalindrome(string &s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            if (s[l] != s[r])
                return 0;
        return 1;
    }
    
public:
    int removePalindromeSub(string s) {
        return 2 - isPalindrome(s);
    }
};