class Solution {
public:
    int countDigitOccurrences(vector<int> &a, int digit) {
        int res = 0;
        for (int value : a) {
            string s = to_string(value);
            res += count(s.begin(), s.end(), digit + '0');
        }
        return res;
    }
};