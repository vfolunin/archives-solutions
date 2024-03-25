class Solution {
public:
    int minOperations(int threshold) {
        int res = 1e9;
        for (int value = 1; value <= threshold; value++) {
            int count = (threshold + value - 1) / value;
            res = min(res, value - 1 + count - 1);
        }
        return res;
    }
};