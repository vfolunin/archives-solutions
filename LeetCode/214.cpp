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
    string shortestPalindrome(string &s) {
        string t = s + "#";
        t.insert(t.end(), s.rbegin(), s.rend());
        return string(s.rbegin(), s.rbegin() + s.size() - prefixFunction(t).back()) + s;
    }
};