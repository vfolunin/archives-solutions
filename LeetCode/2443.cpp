class Solution {
    int reverse(int n) {
        int res = 0;
        while (n > 9) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        res = res * 10 + n;
        return res;
    }
    
public:
    bool sumOfNumberAndReverse(int n) {
        for (int i = 0; i <= n; i++)
            if (n - i == reverse(i))
                return 1;
        return 0;
    }
};