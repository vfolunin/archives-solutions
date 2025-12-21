class Solution {
    long long rec(long long size, int bit, long long value, bool fromLeft) {
        if (size == 1)
            return value;

        if (size % 2 == 0 && !fromLeft)
            value |= 1LL << bit;

        return rec((size + 1) / 2, bit + 1, value, fromLeft ^ 1);
    }

public:
    long long lastInteger(long long size) {
        return rec(size, 0, 0, 1) + 1;
    }
};