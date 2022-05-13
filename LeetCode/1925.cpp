class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int c = 1; c <= n; c++) {
            for (int a = 1; a * a < c * c; a++) {
                int b = sqrt(c * c - a * a);
                res += a * a + b * b == c * c;
            }
        }
        return res;
    }
};