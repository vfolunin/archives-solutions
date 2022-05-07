class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        for (int i = s.size() - 1, count = 0; i >= 0; i--) {
            if (s[i] == '-')
                continue;
            res += toupper(s[i]);
            if (++count == k) {
                count = 0;
                res += '-';
            }
        }
        
        if (res.back() == '-')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};