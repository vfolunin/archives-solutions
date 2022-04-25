class Solution {
public:
    double average(vector<int> &a) {
        int sum = 0, minValue = a[0], maxValue = a[0];
        for (int value : a) {
            sum += value;
            minValue = min(minValue, value);
            maxValue = max(maxValue, value);
        }
        sum -= minValue + maxValue;
        return sum / (a.size() - 2.0);
    }
};