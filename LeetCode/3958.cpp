class Solution {
public:
    long long minCost(int n) {
        return n * (n - 1LL) / 2;
    }
};