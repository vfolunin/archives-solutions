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
    int sumOfTheDigitsOfHarshadNumber(int n) {
        int sum = digitSum(n);
        return n % sum ? -1 : sum;
    }
};