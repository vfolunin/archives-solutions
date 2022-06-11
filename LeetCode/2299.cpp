class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        if (s.size() < 8)
            return 0;
        
        bool lower = 0, upper = 0, digit = 0, special = 0;
        for (int i = 0; i < s.size(); i++) {
            if (islower(s[i]))
                lower = 1;
            else if (isupper(s[i]))
                upper = 1;
            else if (isdigit(s[i]))
                digit = 1;
            else
                special = 1;
            if (i && s[i - 1] == s[i])
                return 0;
        }
        
        return lower && upper && digit && special;
    }
};