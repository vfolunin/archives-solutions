class Solution {
    long long bitCount(int bit, long long r) {
        r++;
        long long cycleSize = 1LL << (bit + 1);
        long long bitCountPerCycle = 1LL << bit;
        long long res = r / cycleSize * bitCountPerCycle;
        res += max(r % cycleSize - bitCountPerCycle, 0LL);
        return res;
    }

    bool can(long long limit, int d, long long r) {
        long long totalBitCount = 0;
        for (int bit = 0; bit < 60 && totalBitCount <= limit; bit++)
            if ((bit + 1) % d == 0)
                totalBitCount += bitCount(bit, r);
        return totalBitCount <= limit;
    }

public:
    long long findMaximumNumber(long long limit, int d) {
        long long l = 0, r = 1;
        while (can(limit, d, r))
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(limit, d, m))
                l = m;
            else
                r = m;
        }

        return l;
    }
};