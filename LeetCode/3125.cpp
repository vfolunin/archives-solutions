class Solution {
public:
    long long maxNumber(long long n) {
        long long res = n;
        for (int bit = 0; bit < 60; bit++)
            if (n & (1LL << bit))
                res = min(res, (n & (-1LL << bit)) - 1);
        return res;
    }
};