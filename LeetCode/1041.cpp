class Solution {
public:
    bool isRobotBounded(string &ops) {
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        int y = 0, x = 0, d = 2;
        
        for (char op : ops) {
            if (op == 'G') {
                y += dy[d];
                x += dx[d];
            } else if (op == 'L') {
                d = (d + 3) % 4;
            } else {
                d = (d + 1) % 4;
            }
        }
        
        return !y && !x || d != 2;
    }
};