class Solution {
    bool between(int a, int b, int c) {
        return a < b && b < c || a > b && b > c;
    }

public:
    int minMovesToCaptureTheQueen(int x1, int y1, int x2, int y2, int x3, int y3) {
        if (x1 == x3 && (x1 != x2 || !between(y1, y2, y3)) ||
            y1 == y3 && (y1 != y2 || !between(x1, x2, x3)) ||
            x2 + y2 == x3 + y3 && (x1 + y1 != x2 + y2 || !between(x2, x1, x3)) ||
            x2 - y2 == x3 - y3 && (x1 - y1 != x2 - y2 || !between(x2, x1, x3)))
            return 1;
        else
            return 2;
    }
};