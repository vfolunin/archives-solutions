class Solution {
    int getMinDivisor(int n) {
        for (long long d = 2; d * d <= n; d++)
            if (n % d == 0)
                return d;
        return n;
    }

public:
    long long minimumMaxValue(int size, int index, int value) {
        if (value == 1)
            return -1;

        long long d = getMinDivisor(value);

        long long l = value;
        if (index)
            l -= d + 2LL * (index - 1);
        if (l <= 0)
            return -1;
        
        long long r = value;
        if (index + 1 < size)
            r += d + 2LL * (size - index - 2);
        return r;
    }
};