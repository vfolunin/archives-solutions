class Solution {
public:
    bool makePalindrome(string &s) {
        int diff = 0;
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            diff += s[l] != s[r];
        return diff <= 2;
    }
};