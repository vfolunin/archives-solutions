class Solution {
public:
    long long minCuttingCost(int a, int b, int limit) {
        long long res = 0;
        if (a > limit)
            res += 1LL * (a - limit) * limit;
        if (b > limit)
            res += 1LL * (b - limit) * limit;
        return res;
    }
};
