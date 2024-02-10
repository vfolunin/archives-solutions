class Solution {
public:
    int countKeyChanges(string s) {
        int res = 0;
        for (int i = 0; i + 1 < s.size(); i++)
            res += tolower(s[i]) != tolower(s[i + 1]);
        return res;
    }
};