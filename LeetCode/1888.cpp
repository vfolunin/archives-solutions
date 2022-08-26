class Solution {
public:
    int minFlips(string &s) {
        s += s;
        
        int k0 = 0, k1 = 0;
        for (int i = 0; i < s.size() / 2; i++) {
            k0 += s[i] - '0' != i % 2;
            k1 += s[i] - '0' != 1 - i % 2;
        }
        
        int res = min(k0, k1);
        
        for (int i = s.size() / 2, j = 0; i < s.size(); i++, j++) {
            k0 -= s[j] - '0' != j % 2;
            k1 -= s[j] - '0' != 1 - j % 2;
            k0 += s[i] - '0' != i % 2;
            k1 += s[i] - '0' != 1 - i % 2;
            res = min({ res, k0, k1 });
        }
        
        return res;
    }
};