class Solution {
public:
    int tribonacci(int n) {
        long long a = 0, b = 0, c = 0, d = 1;
        for (int i = 0; i < n; i++) {
            a = b;
            b = c;
            c = d;
            d = a + b + c;
        }
        return c;
    }
};