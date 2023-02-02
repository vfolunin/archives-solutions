class Solution {
    int rotate(int n) {
        static const vector<int> DIGITS = { 0, 1, -1, -1, -1, -1, 9, -1, 8, 6 };
        int res = 0;
        
        for ( ; n >= 10; n /= 10) {
            if (DIGITS[n % 10] == -1)
                return -1;
            res = res * 10 + DIGITS[n % 10];
        }

        if (DIGITS[n] == -1)
            return -1;
        res = res * 10 + DIGITS[n];

        return res;
    }

public:
    bool confusingNumber(int n) {
        int r = rotate(n);
        return r != -1 && r != n;
    }
};