class Solution {
public:
    int countSegments(string s) {
        int res = !s.empty() && s[0] != ' ';
        for (int i = 1; i < s.size(); i++)
            res += s[i - 1] == ' ' && s[i] != ' ';
        return res;
    }
};