class Solution {
public:
    int finalPositionOfSnake(int size, vector<string> &ops) {
        int y = 0, x = 0;
        for (string &op : ops) {
            y -= op == "UP";
            y += op == "DOWN";
            x -= op == "LEFT";
            x += op == "RIGHT";
        }
        return y * size + x;
    }
};