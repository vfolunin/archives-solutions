class Solution {
public:
    int longestSubarray(vector<int> &a) {        
        int maxValue = 0, maxRow = 0, curRow = 0;
        for (int value : a) {
            if (maxValue < value) {
                maxValue = value;
                maxRow = curRow = 1;
            } else if (maxValue == value) {
                curRow++;
                maxRow = max(maxRow, curRow);
            } else {
                curRow = 0;
            }
        }
        return maxRow;
    }
};