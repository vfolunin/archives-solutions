class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            s[l] = s[r] = min(s[l], s[r]);
        return s;
    }
};