class Solution {
    int getCount(string &s) {
        int count = 0;
        for (int i = 0; i + 1 < s.size(); i++)
            count += s[i] == s[i + 1];
        return count;
    }

public:
    int countRotations(string &s, int targetCount) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += getCount(s) == targetCount;
            rotate(s.begin(), s.begin() + 1, s.end());
        }
        return res;
    }
};