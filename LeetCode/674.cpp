class Solution {
public:
    int findLengthOfLCIS(vector<int> &a) {
        int curRow = 1, maxRow = 1;
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] < a[i])
                curRow++;
            else
                curRow = 1;
            maxRow = max(maxRow, curRow);
        }
        return maxRow;
    }
};