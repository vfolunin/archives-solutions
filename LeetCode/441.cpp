class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 0, r = n + 1LL;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (m * (m + 1) / 2 <= n)
                l = m;
            else
                r = m;
        }
        return l;
    }
};