class Solution {
    long long binPow(long long x, long long p) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1) * x;
        long long r = binPow(x, p / 2);
        return r * r;
    }

public:
    int countKthRoots(int l, int r, int p) {
        if (p == 1)
            return r - l + 1;

        int res = 0;
        for (int i = 0; 1; i++) {
            int value = binPow(i, p);
            if (value > r)
                break;
            res += l <= value;
        }
        return res;
    }
};