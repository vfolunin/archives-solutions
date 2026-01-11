class Solution {
    int getOps(int value, int targetMask) {
        int targetValue = value;
        for (int divisor = 1 << 30; divisor; divisor /= 2)
            if ((targetMask & divisor) && !(targetValue & divisor))
                targetValue += divisor - targetValue % divisor;
        return targetValue - value;
    }

public:
    int maximumAND(vector<int> &a, int opLimit, int subsetSize) {
        int resMask = 0;
        for (int bit = 30; bit >= 0; bit--) {
            int targetMask = resMask | (1 << bit);

            vector<int> ops;
            for (int value : a)
                ops.push_back(getOps(value, targetMask));
                
            nth_element(ops.begin(), ops.begin() + subsetSize, ops.end());
            if (accumulate(ops.begin(), ops.begin() + subsetSize, 0LL) <= opLimit)
                resMask = targetMask;
        }
        return resMask;
    }
};