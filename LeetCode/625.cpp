class Solution {
public:
    int smallestFactorization(int n) {
        if (n == 1)
            return 1;

        long long res = 0, power = 1;
        for (int d = 9; d > 1; d--) {
            while (n % d == 0) {
                n /= d;
                res = res + d * power;
                power *= 10;
            }
        }

        return n == 1 && res <= 0x7fffffff ? res : 0;
    }
};