class Solution {
public:
    bool checkPerfectNumber(int n) {
        int sum = 1;
        for (int d = 2; d * d <= n; d++) {
            if (n % d == 0) {
                sum += d;
                if (d * d != n)
                    sum += n / d;
            }
        }
        return n > 1 && sum == n;
    }
};