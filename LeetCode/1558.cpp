class Solution {
public:
    int minOperations(vector<int> &a) {
        int res = 0, maxLength = 0;
        for (int value : a) {
            int length = 1;
            while (value > 1) {
                length++;
                res += value % 2;
                value /= 2;
            }
            res += value;
            maxLength = max(maxLength, length);
        }
        return res + maxLength - 1;
    }
};