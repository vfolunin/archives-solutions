class Solution {
public:
    int findNumber() {
        int res = 0;
        for (int bit = 0; bit < 30; bit++) {
            int a = commonBits(1 << bit);
            int b = commonBits(1 << bit);
            res |= (a > b) << bit;
        }
        return res;
    }
};