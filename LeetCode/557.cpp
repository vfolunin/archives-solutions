class Solution {
public:
    string reverseWords(string s) {
        for (int l = 0; l < s.size(); ) {
            while (l < s.size() && s[l] == ' ')
                l++;
            
            int r = l;
            while (r < s.size() && s[r] != ' ')
                r++;
            
            reverse(s.begin() + l, s.begin() + r);
            
            l = r;
        }
        
        return s;
    }
};