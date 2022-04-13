class Solution {
public:
    int lengthOfLastWord(const string &s) {
        int r = s.size() - 1;
        while (s[r] == ' ')
            r--;
        return r - s.rfind(' ', r);
    }
};