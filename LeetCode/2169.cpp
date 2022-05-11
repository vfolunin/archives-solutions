class Solution {
public:
    int countOperations(int a, int b) {
        int res = 0;
        while (a && b) {
            if (a >= b) {
                res += a / b;
                a %= b;
            } else {
                res += b / a;
                b %= a;
            }
        }
        return res;
    }
};