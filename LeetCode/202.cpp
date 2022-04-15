class Solution {
public:
    bool isHappy(int n) {
        if (n < 10)
            return n == 1 || n == 7;
        
        int digitSquareSum = 0;
        while (n) {
            digitSquareSum += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return isHappy(digitSquareSum);
    }
};