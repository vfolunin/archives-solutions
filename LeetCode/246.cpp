class Solution {
    string rotate(string &s) {
        static const string DIGITS = "01----9-86";
        string res;
        
        for (char c : s) {
            if (DIGITS[c - '0'] == '-')
                return "";
            res += DIGITS[c - '0'];
        }

        reverse(res.begin(), res.end());
        return res;
    }

public:
    bool isStrobogrammatic(string &s) {
        return s == rotate(s);
    }
};