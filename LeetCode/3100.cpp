class Solution {
public:
    int maxBottlesDrunk(int num, int den) {
        int res = 0;
        while (num >= den) {
            res += den;
            num -= den - 1;
            den++;
        }
        res += num;
        return res;
    }
};