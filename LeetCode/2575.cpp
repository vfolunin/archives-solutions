class Solution {
public:
    vector<int> divisibilityArray(string &number, int divisor) {
        vector<int> res(number.size());
        long long remainder = 0;

        for (int i = 0; i < number.size(); i++) {
            remainder = (remainder * 10 + number[i] - '0') % divisor;
            res[i] = !remainder;
        }

        return res;
    }
};