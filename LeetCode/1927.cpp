class Solution {
public:
    bool sumGame(string &s) {
        int questionBalance = 0, sumBalance = 0;
        
        for (int i = 0; i < s.size(); i++) {
            int sign = i * 2 < s.size() ? 1 : -1;
            if (s[i] == '?')
                questionBalance += sign;
            else
                sumBalance += (s[i] - '0') * sign;
        }
        
        return questionBalance % 2 || questionBalance * 9 != sumBalance * -2;
    }
};