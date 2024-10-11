class Solution {
    long long c(long long n, long long k) {
        long long res = 1;
        for (long long i = n; i > n - k; i--)
            res *= i;
        for (long long i = 1; i <= k; i++)
            res /= i;
        return res;
    }

    long long getWays(long long n) {
        return n >= 0 ? c(n + 2, 2) : 0;
    }

public:
    long long distributeCandies(int n, int limit) {
        limit++;
        long long res = getWays(n);
        res -= 3 * getWays(n - limit);
        res += 3 * getWays(n - 2 * limit);
        res -= getWays(n - 3 * limit);
        return res;
    }
};