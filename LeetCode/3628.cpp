class Solution {
public:
    long long numOfSubsequences(string &s) {
        vector<long long> l(s.size()), lc(s.size());
        for (int i = 0; i < s.size(); i++) {
            l[i] = (i ? l[i - 1] : 0) + (s[i] == 'L');
            lc[i] = (i ? lc[i - 1] : 0) + (s[i] == 'C' ? l[i] : 0);
        }
        
        vector<long long> t(s.size()), ct(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            t[i] = (i + 1 < s.size() ? t[i + 1] : 0) + (s[i] == 'T');
            ct[i] = (i + 1 < s.size() ? ct[i + 1] : 0) + (s[i] == 'C' ? t[i] : 0);
        }

        long long res = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'C')
                res += l[i] * t[i];
        
        long long delta = 0;
        for (int i = 0; i < s.size(); i++)
            delta = max({ delta, ct[i], l[i] * t[i], lc[i] });
        res += delta;

        return res;
    }
};