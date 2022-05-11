class Solution {
public:
    int brokenCalc(int a, int b) {
        int res = 0;
        while (a < b) {
            if (b % 2)
                b++;
            else
                b /= 2;
            res++;
        }
        res += a - b;
        return res;
    }
};
