class Solution {
public:
    int newInteger(int n) {
        int res = 0;
        for (long long width = 1; n; n /= 9, width *= 10)
            res += n % 9 * width;
        return res;
    }
};