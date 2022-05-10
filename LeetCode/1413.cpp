class Solution {
public:
    int minStartValue(vector<int> &a) {
        int sum = 0, minSum = 0;
        for (int value : a) {
            sum += value;
            minSum = min(minSum, sum);
        }
        return max(-minSum, 0) + 1;
    }
};