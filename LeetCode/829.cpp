class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res = 0;
        for (int k = 1; (1 + k) * k <= 2 * n; k++) {
            if (2 * n % k)
                continue;
            int twoX = 2 * n / k + 1 - k;
            res += twoX % 2 == 0 && twoX >= 2;
        }
        return res;
    }
};