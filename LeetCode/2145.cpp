class Solution {
public:
    int numberOfArrays(vector<int> &diffs, int l, int r) {
        long long value = 0, minValue = 0, maxValue = 0;
        for (int diff : diffs) {
            value += diff;
            minValue = min(minValue, value);
            maxValue = max(maxValue, value);
        }
        
        long long delta = l - minValue;
        minValue += delta;
        maxValue += delta;
        
        return max<int>(r - maxValue + 1, 0);
    }
};