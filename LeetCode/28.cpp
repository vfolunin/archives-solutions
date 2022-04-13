class Solution {
public:
    int strStr(const string &text, const string &pattern) {
        string s = pattern + "#" + text;
        
        vector<int> p(s.size());
        for (int i = 1; i < s.size(); i++) {
            int border = p[i - 1];
            while (border > 0 && s[i] != s[border])
                border = p[border - 1];
            p[i] = border + (s[i] == s[border]);
            
            if (p[i] == pattern.size())
                return i - pattern.size() * 2;
        }
        
        return -1;
    }
};