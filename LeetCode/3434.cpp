class Solution {
    int getMaxRow(vector<int> &a, int incValue, int decValue) {
        int row = 0, res = 0;
        for (int value : a) {
            row += value == incValue;
            row -= value == decValue;
            row = max(row, 0);
            res = max(res, row);
        }
        return res;
    }

public:
    int maxFrequency(vector<int> &a, int target) {
        int res = 0;
        for (int value = 0; value <= 50; value++)
            res = max(res, getMaxRow(a, value, target));
        return count(a.begin(), a.end(), target) + res;
    }
};