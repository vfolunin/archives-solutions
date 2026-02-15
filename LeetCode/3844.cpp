class Solution {
    int check(string &s, int l, int r) {
        while (0 <= l && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }

public:
    int almostPalindromic(string &s) {
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            int l = i - 1, r = i + 1;
            while (0 <= l && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
            }

            res = max(res, r - l - 1);
            if (0 <= l)
                res = max(res, check(s, l - 1, r));
            if (r < s.size())
                res = max(res, check(s, l, r + 1));
        }

        for (int i = 0; i + 1 < s.size(); i++) {
            int l = i, r = i + 1;
            while (0 <= l && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
            }

            res = max(res, r - l - 1);
            if (0 <= l)
                res = max(res, check(s, l - 1, r));
            if (r < s.size())
                res = max(res, check(s, l, r + 1));
        }

        return res;
    }
};