class Solution {
public:
    int longestMonotonicSubarray(vector<int> &a) {
        int incRow = 1, decRow = 1, maxRow = 1;
        for (int i = 1; i < a.size(); i++) {
            incRow = a[i - 1] < a[i] ? incRow + 1 : 1;
            decRow = a[i - 1] > a[i] ? decRow + 1 : 1;
            maxRow = max({ maxRow, incRow, decRow });
        }
        return maxRow;
    }
};