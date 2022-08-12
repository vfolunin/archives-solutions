class Solution {
public:
    int minInsertions(string &s) {
        int balance = 0, res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                balance++;
            } else if (i + 1 < s.size() && s[i + 1] == ')') {
                balance--;
                i++;
            } else {
                balance--;
                res++;
            }
            
            if (balance < 0) {
                balance++;
                res++;
            }
        }
        
        res += balance * 2;
        
        return res;
    }
};