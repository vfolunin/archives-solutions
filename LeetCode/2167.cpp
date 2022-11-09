class Solution {
public:
    int minimumTime(string &s) {
        if (s.size() == 1)
            return s[0] == '1';
        
        vector<int> l(s.size());
        l[0] = s[0] == '1';
        for (int i = 1; i < s.size(); i++) {
            l[i] = l[i - 1];
            if (s[i] == '1')
                l[i] = min(i + 1, l[i - 1] + 2);
        }
        
        vector<int> r(s.size());
        r[s.size() - 1] = s[s.size() - 1] == '1';
        for (int i = (int)s.size() - 2; i >= 0; i--) {
            r[i] = r[i + 1];
            if (s[i] == '1')
                r[i] = r.size() - i;
        }
        
        int res = 1e9;
        for (int i = 0; i + 1 < s.size(); i++)
            res = min(res, l[i] + r[i + 1]);
        return res;
    }
};