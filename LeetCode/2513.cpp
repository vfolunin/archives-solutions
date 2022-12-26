class Solution {
    bool can(long long d1, long long d2, long long size1, long long size2, long long n) {
        long long count12 = n / lcm(d1, d2);
        long long count1 = n / d1 - count12;
        long long count2 = n / d2 - count12;

        n -= count1 + count2 + count12;
        size1 = max(size1 - count2, 0LL);
        size2 = max(size2 - count1, 0LL);

        return size1 + size2 <= n;
    }

public:
    int minimizeSet(long long d1, long long d2, long long size1, long long size2) {
        long long l = 0, r = 1e18;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(d1, d2, size1, size2, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};