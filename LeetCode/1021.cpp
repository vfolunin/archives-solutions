class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (depth++)
                    res += c;
            } else {
                if (--depth)
                    res += c;
            }
        }
        
        return res;
    }
};