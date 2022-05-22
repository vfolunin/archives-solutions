class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        
        for (int i = 0; i < s.size(); i++)
            for (int l = i, r = i; 0 <= l && r < s.size() && s[l] == s[r]; l--, r++)
                res++;
        
        for (int i = 1; i < s.size(); i++)
            for (int l = i - 1, r = i; 0 <= l && r < s.size() && s[l] == s[r]; l--, r++)
                res++;
        
        return res;
    }
};