class Solution {
    bool isPalindrome(string &s, int l, int r) {
        for ( ; l < r; l++, r--)
            if (s[l] != s[r])
                return 0;
        return 1;
    }
    
    bool check(string &a, string &b) {
        for (int l = 0, r = b.size() - 1; l < r; l++, r--)
            if (a[l] != b[r])
                return isPalindrome(a, l, r) || isPalindrome(b, l, r);
        return 1;
    }
    
public:
    bool checkPalindromeFormation(string &a, string &b) {
        return check(a, b) || check(b, a);
    }
};