class Solution {
public:
    int firstMatchingIndex(string &s) {
        for (int l = 0, r = s.size() - 1; l <= r; l++, r--)
            if (s[l] == s[r])
                return l;
        return -1;
    }
};