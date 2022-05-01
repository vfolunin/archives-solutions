class Solution {
public:
    int secondHighest(string s) {
        int maxDigit = -1, secondMaxDigit = -1;
        for (char c : s) {
            if (!isdigit(c))
                continue;
            if (c - '0' > maxDigit) {
                secondMaxDigit = maxDigit;
                maxDigit = c - '0';
            } else if (c - '0' < maxDigit && c - '0' > secondMaxDigit) {
                secondMaxDigit = c - '0';
            }
        }
        return secondMaxDigit;
    }
};