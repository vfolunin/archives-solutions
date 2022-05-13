class Solution {
public:
    bool judgeSquareSum(long long c) {
        for (long long a = 0; 2 * a * a <= c; a++) {
            long long b = sqrt(c - a * a);
            if (a * a + b * b == c)
                return 1;
        }
        return 0;
    }
};