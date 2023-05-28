class Solution {
public:
    long long minimumCost(string &s) {
        vector<long long> l0(s.size());
        vector<long long> l1(s.size());
        
        l0[0] = s[0] == '1';
        l1[0] = s[0] == '0';
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                l0[i] = l0[i - 1];
                l1[i] = l0[i - 1] + i + 1;
            } else {
                l0[i] = l1[i - 1] + i + 1;
                l1[i] = l1[i - 1];
            }
        }
        
        vector<long long> r0(s.size());
        vector<long long> r1(s.size());
        
        r0.back() = s.back() == '1';
        r1.back() = s.back() == '0';
        
        for (int i = (int)s.size() - 2; i >= 0; i--) {
            if (s[i] == '0') {
                r0[i] = r0[i + 1];
                r1[i] = r0[i + 1] + (int)s.size() - i;
            } else {
                r0[i] = r1[i + 1] + (int)s.size() - i;
                r1[i] = r1[i + 1];
            }
        }
        
        long long res = min({ r0[0], r1[0], l0.back(), l1.back() });
        for (int i = 0; i + 1 < s.size(); i++)
            res = min({ res, l0[i] + r0[i + 1], l1[i] + r1[i + 1] });
        return res;
    }
};