class Solution {
    bool rec(string &p, int pi, string &s, int si, vector<string> &matching) {
        if (pi == p.size())
            return si == s.size();
        if (si == s.size())
            return 0;
        
        string &m = matching[p[pi] - 'a'];
        if (!m.empty()) {
            if (si + m.size() > s.size() || s.substr(si, m.size()) != m)
                return 0;
            else
                return rec(p, pi + 1, s, si + m.size(), matching);
        }

        for (int size = 1; si + size <= s.size(); size++) {
            m += s[si + size - 1];
            if (count(matching.begin(), matching.end(), m) == 1 && rec(p, pi + 1, s, si + size, matching))
                return 1;
        }

        m.clear();
        return 0;
    }

public:
    bool wordPatternMatch(string &p, string &s) {
        vector<string> matching(26);
        return rec(p, 0, s, 0, matching);
    }
};