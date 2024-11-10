class Solution {
    bool isGood(int n, int d) {
        int remainder = 1 % d;
        while (n) {
            remainder = remainder * (n % 10) % d;
            n /= 10;
        }
        return !remainder;
    }

public:
    int smallestNumber(int n, int d) {
        while (!isGood(n, d))
            n++;
        return n;
    }
};