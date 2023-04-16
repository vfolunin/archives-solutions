class Solution {
public:
    int addMinimum(string &s) {
        vector<int> res(s.size() + 1);
        for (int len = 1; len <= s.size(); len++) {
            if (len >= 3 && s[len - 3] < s[len - 2] && s[len - 2] < s[len - 1])
                res[len] = res[len - 3];
            else if (len >= 2 && s[len - 2] < s[len - 1])
                res[len] = res[len - 2] + 1;
            else
                res[len] = res[len - 1] + 2;
        }
        return res[s.size()];
    }
};