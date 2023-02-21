class Solution {
    long long makeValue(int size, int mask, int a, int b) {
        long long res = 0;
        for (int i = 0; i < size; i++) {
            res = res * 10 + (mask % 2 ? a : b);
            mask /= 2;
        }
        return res;
    }

public:
    int findInteger(int value, int a, int b) {
        int res = -1;
        for (int size = 1; size <= 10; size++) {
            for (int mask = 0; mask < (1 << size); mask++) {
                long long candidate = makeValue(size, mask, a, b);
                if (value < candidate && candidate % value == 0 && candidate <= 0x7fffffff && (res == -1 || res > candidate))
                    res = candidate;
            }
        }
        return res;
    }
};