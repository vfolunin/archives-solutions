class Solution {
public:
    bool judgeCircle(string moves) {
        int y = 0, x = 0;
        for (char move : moves) {
            if (move == 'U')
                y++;
            else if (move == 'R')
                x++;
            else if (move == 'D')
                y--;
            else
                x--;
        }
        return !y && !x;
    }
};