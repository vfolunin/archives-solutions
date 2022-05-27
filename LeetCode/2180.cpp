class Solution {
    int digitSum(int n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    
public:
    int countEven(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++)
            res += digitSum(i) % 2 == 0;
        return res;
    }
};