class Solution {
public:
    int kItemsWithMaximumSum(int kPos, int kZero, int kNeg, int k) {
        int delta = min(k, kPos), sum = delta;
        k -= delta;
        delta = min(k, kZero);
        k -= delta;
        sum -= min(k, kNeg);
        return sum;
    }
};