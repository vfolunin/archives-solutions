class Solution {
    bool isPalindrome(const string &s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            if (s[l] != s[r])
                return 0;
        return 1;
    }

public:
    int longestPalindrome(string &a, string &b) {
        int res = 0;
        for (int al = 0; al < a.size(); al++)
            for (int ar = al; ar <= a.size(); ar++)
                for (int bl = 0; bl < b.size(); bl++)
                    for (int br = bl; br <= b.size(); br++)
                        if (isPalindrome(a.substr(al, ar - al) + b.substr(bl, br - bl)))
                            res = max(res, ar - al + br - bl);
        return res;
    }
};