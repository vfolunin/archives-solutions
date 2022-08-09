class Solution {
public:
    string alphabetBoardPath(string &s) {
        string res;
        int y = 0, x = 0;
        
        for (char c : s) {
            int cy = (c - 'a') / 5;
            int cx = (c - 'a') % 5;
            
            if (y <= cy) {
                if (x <= cx)
                    res += string(cx - x, 'R');
                else
                    res += string(x - cx, 'L');
                res += string(cy - y, 'D');
            } else {
                res += string(y - cy, 'U');
                if (x <= cx)
                    res += string(cx - x, 'R');
                else
                    res += string(x - cx, 'L');
            }
            res += "!";
            
            y = cy;
            x = cx;
        }
        
        return res;
    }
};