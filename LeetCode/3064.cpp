class Solution {
public:
    int findNumber() {
        int res = 0;
        for (int bit = 0; bit < 30; bit++)
            res |= commonSetBits(1 << bit) << bit;
        return res;
    }
};