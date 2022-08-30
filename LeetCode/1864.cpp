class Solution {
public:
    int minSwaps(string &s) {
        int res = s.size();
        
        int k01 = 0, k10 = 0;
        for (int i = 0; i < s.size(); i++) {
            k01 += i % 2 && s[i] == '0';
            k10 += i % 2 == 0 && s[i] == '1';
        }
        
        if (k01 == k10)
            res = min(res, k01);
        
        k01 = 0;
        k10 = 0;
        for (int i = 0; i < s.size(); i++) {
            k01 += i % 2 == 0 && s[i] == '0';
            k10 += i % 2 && s[i] == '1';
        }
        
        if (k01 == k10)
            res = min(res, k01);
        
        if (res == s.size())
            res = -1;
        
        return res;
    }
};