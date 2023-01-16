class Solution {
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int differenceOfSum(vector<int> &a) {
        int sum1 = 0, sum2 = 0;
        for (int value : a) {
            sum1 += value;
            sum2 += digitSum(value);
        }
        return abs(sum1 - sum2);
    }
};