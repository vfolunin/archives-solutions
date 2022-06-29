class Solution {
public:
    bool canMeasureWater(int a, int b, int c) {
        return c <= a + b && c % gcd(a, b) == 0;
    }
};