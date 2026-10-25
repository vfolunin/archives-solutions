class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }

public:
    int calculateScore(int a, int b) {
        a = ones(a);
        b = ones(b);

        return a >= b ? a * b : b / a;
    }
};