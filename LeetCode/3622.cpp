class Solution {
    int getDivisor(int n) {
        int sum = 0, product = 1;
        while (n) {
            sum += n % 10;
            product *= n % 10;
            n /= 10;
        }
        return sum + product;
    }

public:
    bool checkDivisibility(int n) {
        return n % getDivisor(n) == 0;
    }
};