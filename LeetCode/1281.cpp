class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while (n) {
            int digit = n % 10;
            product *= digit;
            sum += digit;
            n /= 10;
        }
        return product - sum;
    }
};