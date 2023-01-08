class Solution {
public:
    int maximumCount(vector<int> &a) {
        int positiveCount = 0, negativeCount = 0;
        for (int value : a) {
            positiveCount += value > 0;
            negativeCount += value < 0;
        }
        return max(positiveCount, negativeCount);
    }
};