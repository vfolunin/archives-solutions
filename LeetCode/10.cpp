class Solution {
public:
    bool isMatch(string &s, string &p) {
        vector<vector<int>> res(s.size() + 1, vector<int>(p.size() + 1));
        res[0][0] = 1;
        
        for (int si = 0; si <= s.size(); si++) {
            for (int pi = 1; pi <= p.size(); pi++) {
                if (si && (s[si - 1] == p[pi - 1] || p[pi - 1] == '.')) {
                    res[si][pi] = res[si - 1][pi - 1];
                } else if (p[pi - 1] == '*') {
                    res[si][pi] = res[si][pi - 2];
                    for (int i = si; i; i--) {
                        if (s[i - 1] == p[pi - 2] || p[pi - 2] == '.')
                            res[si][pi] |= res[i - 1][pi - 2];
                        else
                            break;
                    }
                }
            }
        }
        
        return res[s.size()][p.size()];
    }
};