class Solution {
    void rec(long long value, vector<long long> &values) {
        if (value > 2e9)
            return;

        values.push_back(value);
        
        int digit = value % 10;
        if (digit)
            rec(value * 10 + digit - 1, values);
        if (digit < 9)
            rec(value * 10 + digit + 1, values);
    }

public:
    vector<int> countSteppingNumbers(int l, int r) {
        vector<long long> values = { 0 };
        for (int i = 1; i <= 9; i++)
            rec(i, values);
        sort(values.begin(), values.end());

        auto lIt = lower_bound(values.begin(), values.end(), l);
        auto rIt = upper_bound(values.begin(), values.end(), r);
        return { lIt, rIt };
    }
};