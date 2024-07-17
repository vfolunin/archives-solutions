class Solution {
public:
    string getSmallestString(string &s) {
        string res = s;
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] % 2 == s[i + 1] % 2) {
                swap(s[i], s[i + 1]);
                res = min(res, s);
                swap(s[i], s[i + 1]);
            }
        }
        return res;
    }
};