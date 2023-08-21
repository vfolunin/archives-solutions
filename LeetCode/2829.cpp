class Solution {
    int getSum(int l, int r) {
        return (l + r) * (r - l + 1) / 2;
    }

public:
    int minimumSum(int size, int sum) {
        int res = getSum(1, min(size, sum / 2));

        if (size > sum / 2)
            res += getSum(sum, sum + size - sum / 2 - 1);

        return res;
    }
};