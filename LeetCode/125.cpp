class Solution {
public:
    bool isPalindrome(const string &s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
            while (l < r && !isalnum(s[l]))
                l++;
            while (l < r && !isalnum(s[r]))
                r--;
            if (tolower(s[l]) != tolower(s[r]))
                return false;
        }
        return true;
    }
};