class Solution {
public:
    int minMoves(int ax, int ay, int bx, int by) {
        int res = 0;

        for (; ax < bx || ay < by; res++) {
            if (bx > by) {
                swap(ax, ay);
                swap(bx, by);
            }

            if (bx * 2 <= by) {
                if (by % 2)
                    return -1;
                by /= 2;
            } else if (bx == by) {
                if (ax == 0)
                    bx = 0;
                else
                    by = 0;
            } else {
                by -= bx;
            }
        }

        return ax == bx && ay == by ? res : -1;
    }
};