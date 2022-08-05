class Solution {
public:
    string addSpaces(string &s, vector<int> &a) {
        string res;
        for (int si = 0, ai = 0; si < s.size(); si++) {
            if (ai < a.size() && si == a[ai]) {
                res += ' ';
                ai++;
            }
            res += s[si];
        }
        return res;
    }
};