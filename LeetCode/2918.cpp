class Solution {
public:
    long long minSum(vector<int> &a, vector<int> &b) {
        long long aSum = 0, aZeroCount = 0;
        for (int value : a) {
            if (value)
                aSum += value;
            else
                aZeroCount++;
        }

        long long bSum = 0, bZeroCount = 0;
        for (int value : b) {
            if (value)
                bSum += value;
            else
                bZeroCount++;
        }

        if (aSum > bSum) {
            swap(aSum, bSum);
            swap(aZeroCount, bZeroCount);
        }

        if (aSum == bSum) {
            if (!aZeroCount && bZeroCount || aZeroCount && !bZeroCount)
                return -1;
            return aSum + max(aZeroCount, bZeroCount);
        } else {
            if (!aZeroCount || aSum + aZeroCount > bSum && !bZeroCount)
                return -1;
            return max(aSum + aZeroCount, bSum + bZeroCount);
        }
    }
};