struct Checker {
    vector<int> has;
    int minValue = 0, maxValue = 0, imbalance = 0;

    Checker(int size) : has(size + 1) {}

    void add(int value) {
        if (has[value])
            return;
        has[value] = 1;

        if (!minValue) {
            minValue = maxValue = value;
            return;
        }

        imbalance -= minValue < value && value < maxValue && has[value - 1] && has[value + 1];
        imbalance += minValue < value && value < maxValue && !has[value - 1] && !has[value + 1] || 
                     value + 1 < minValue || maxValue + 1 < value;

        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }
};

class Solution {
public:
    int sumImbalanceNumbers(vector<int> &a) {
        int res = 0;

        for (int l = 0; l < a.size(); l++) {
            Checker checker(a.size());
            for (int r = l; r < a.size(); r++) {
                checker.add(a[r]);
                res += checker.imbalance;
            }
        }

        return res;
    }
};