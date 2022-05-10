class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res = 0;
        while (target > 1) {
            if (target % 2) {
                res++;
                target--;
            } else if (maxDoubles) {
                res++;
                maxDoubles--;
                target /= 2;
            } else {
                res += target / 2;
                target /= 2;
            }
        }
        return res;
    }
};