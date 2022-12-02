class Solution {
    int getType(char c) {
        if (c == ' ')
            return 0;
        if (c == '+' || c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        if (c == '.')
            return 3;
        if (c == 'e' || c == 'E')
            return 4;
        return 5;
    }
    
public:
    bool isNumber(string &s) {
        int state = 1;        
        vector<vector<int>> transition = {
            { 0, 0, 0, 0, 0, 0 },
            { 1, 2, 3, 4, 0, 0 },
            { 0, 0, 3, 4, 0, 0 },
            { 9, 0, 3, 5, 6, 0 },
            { 0, 0, 5, 0, 0, 0 },
            { 9, 0, 5, 0, 6, 0 },
            { 0, 7, 8, 0, 0, 0 },
            { 0, 0, 8, 0, 0, 0 },
            { 9, 0, 8, 0, 0, 0 },
            { 9, 0, 0, 0, 0, 0 }
        };
        
        for (char c : s)
            state = transition[state][getType(c)];

        return state == 3 || state == 5 || state == 8 || state == 9;
    }
};