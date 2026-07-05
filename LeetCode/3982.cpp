class Solution {
    int getDigitRange(int value) {
        string s = to_string(value);
        auto [minIt, maxIt] = minmax_element(s.begin(), s.end());
        return *maxIt - *minIt;
    }

public:
    int maxDigitRange(vector<int> &a) {
        int maxRange = 0;
        for (int value : a)
            maxRange = max(maxRange, getDigitRange(value));
        
        int res = 0;
        for (int value : a)
            if (getDigitRange(value) == maxRange)
                res += value;
        return res;
    }
};