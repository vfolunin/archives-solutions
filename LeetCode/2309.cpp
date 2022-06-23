class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> lower(26), upper(26);
        for (char c : s) {
            if (islower(c))
                lower[c - 'a'] = 1;
            else
                upper[c - 'A'] = 1;
        }
        
        for (int i = 25; i >= 0; i--)
            if (lower[i] && upper[i])
                return string(1, 'A' + i);
        
        return "";
    }
};