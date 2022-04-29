class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 0, r = num + 1LL;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (m * m <= num)
                l = m;
            else
                r = m;
        }
        return l * l == num;
    }
};