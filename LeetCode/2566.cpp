class Solution {
    int replace(int value, int a, int b) {
        string s = to_string(value);
        for (char &c : s)
            if (c == '0' + a)
                c = '0' + b;
        return stoi(s);
    }

public:
    int minMaxDifference(int value) {
        int minValue = value, maxValue = value;
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                int replacedValue = replace(value, a, b);
                minValue = min(minValue, replacedValue);
                maxValue = max(maxValue, replacedValue);
            }
        }
        return maxValue - minValue;
    }
};