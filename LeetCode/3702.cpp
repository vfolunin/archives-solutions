class Solution {
public:
    int longestSubsequence(vector<int> &a) {
        int xorSum = 0, nonZeroCount = 0;
        for (int value : a) {
            xorSum ^= value;
            nonZeroCount += value != 0;
        }

        if (xorSum)
            return a.size();
        else if (nonZeroCount)
            return a.size() - 1;
        else
            return 0;
    }
};