class Solution {
    int countTo(int digit, int to) {
        int res = 0;

        for (int base = 1; base <= to; base *= 10) {
            int quotient = to / base;
            int remainder = to % base;
            int toDigit = quotient % 10;

            res += quotient / 10 * base;

            if (digit < toDigit)
                res += base;
            else if (digit == toDigit)
                res += remainder + 1;

            if (!digit)
                res -= base;
        }

        return res;
    }

public:
    int digitsCount(int digit, int l, int r) {
        return countTo(digit, r) - countTo(digit, l - 1);
    }
};