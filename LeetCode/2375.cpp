class Solution {
public:
    string smallestNumber(string &s) {
        string res;
        
        int l = 1, row = 0;
        
        for (char c : s) {
            if (c == 'I') {
                for (int i = 0; i < row; i++)
                    res += to_string(l + row - i);
                res += to_string(l);
                l += row + 1;
                row = 0;
            } else {
                row++;
            }
        }
        
        for (int i = 0; i < row; i++)
            res += to_string(l + row - i);
        res += to_string(l);
        
        return res;
    }
};