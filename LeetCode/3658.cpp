class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0, evenSum = 0;
        for (int i = 1; i <= n; i++) {
            oddSum += i * 2 - 1;
            evenSum += i * 2;
        }
        return gcd(oddSum, evenSum);
    }
};