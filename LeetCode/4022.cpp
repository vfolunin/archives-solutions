class Solution {
    long long getDigitCount(long long n) {
        return to_string(n).size();
    }

    long long getPowerOfTen(int power) {
        long long res = 1;
        for (int i = 0; i < power; i++)
            res *= 10;
        return res;
    }

    long long getDigitCountTo(long long r) {
        long long size = getDigitCount(r);
        long long l = getPowerOfTen(size - 1);
        long long res = (r - l + 1) * size;
        if (l > 1)
            res += getDigitCountTo(l - 1);
        return res;
    }

public:
    int kthDigit(long long index) {
        long long l = 0, r = 1;
        while (getDigitCountTo(r) < index)
            r *= 2;

        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (getDigitCountTo(m) < index)
                l = m;
            else
                r = m;
        }

        if (r / 10 % 2)
            r = r / 10 * 10 + 9 - r % 10;

        return to_string(r)[index - getDigitCountTo(l) - 1] - '0';
    }
};