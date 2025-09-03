class Solution {
public:
    int minCost(int h, int w) {
        if (1LL * h * w <= 2)
            return h == w ? 1 : 3;
        else
            return -1;
    }
};