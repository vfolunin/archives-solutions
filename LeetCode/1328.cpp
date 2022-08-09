class Solution {
public:
    string breakPalindrome(string &s) {
        int i = 0;
        while (i < s.size() && s[i] == 'a')
            i++;
        
        if (i < s.size() && (s.size() % 2 == 0 || i != s.size() / 2))
            s[i] = 'a';
        else
            s.back() = 'b';
        
        return s.size() > 1 ? s : "";
    }
};