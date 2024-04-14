class Solution {
public:
    int scoreOfString(string &s) {
        int res = 0;
        for (int i = 0; i + 1 < s.size(); i++)
            res += abs(s[i] - s[i + 1]);
        return res;
    }
};