class Solution {
public:
    int minMoves(vector<int> &a) {
        int sum = 0, maxValue = 0;
        for (int value : a) {
            sum += value;
            maxValue = max(maxValue, value);
        }
        return maxValue * a.size() - sum;
    }
};