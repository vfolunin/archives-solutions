class Solution {
public:
    bool isMatch(string &s, string &p) {
        vector<vector<int>> can(s.size() + 1, vector<int>(p.size() + 1));
        can[0][0] = 1;
        
        for (int si = 0; si <= s.size(); si++) {
            for (int pi = 1; pi <= p.size(); pi++) {
                if (si && (s[si - 1] == p[pi - 1] || p[pi - 1] == '?')) {
                    can[si][pi] = can[si - 1][pi - 1];
                } else if (p[pi - 1] == '*') {
                    for (int sj = 0; sj <= si && !can[si][pi]; sj++)
                        can[si][pi] |= can[sj][pi - 1];
                }                    
            }
        }
        
        return can[s.size()][p.size()];
    }
};