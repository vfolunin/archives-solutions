class Solution {
public:
    long long numberOfWays(string s) {
        vector<int> count(2), l(s.size());
        for (int i = 0; i < s.size(); i++) {
            l[i] = count['1' - s[i]];
            count[s[i] - '0']++;
        }
        
        count.assign(2, 0);
        vector<int> r(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            r[i] = count['1' - s[i]];
            count[s[i] - '0']++;
        }
        
        long long res = 0;
        for (int i = 0; i < s.size(); i++)
            res += 1LL * l[i] * r[i];
        return res;
    }
};