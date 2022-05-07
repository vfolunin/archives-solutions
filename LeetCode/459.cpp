class Solution {
    vector<int> prefixFunction(const string &s) {
        vector<int> p(s.size());
        for (int i = 1; i < s.size(); i++) {
            int border = p[i - 1];
            while (border > 0 && s[i] != s[border])
                border = p[border - 1];
            p[i] = border + (s[i] == s[border]);
        }
        return p;
    }
    
public:
    bool repeatedSubstringPattern(string s) {
        int period = s.size() - prefixFunction(s).back();
        return period != s.size() && s.size() % period == 0;
    }
};